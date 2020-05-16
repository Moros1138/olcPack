#include "olcResourcePack.h"

void Add(olc::ResourcePack *pack, const std::string &sFilename)
{
	if(pack->AddFile(sFilename))
	{
		std::cout << sFilename << " added." << std::endl;
		return;
	}

	std::cout << "ERROR: " << sFilename << " not added. File not found." << std::endl;
}

void List(olc::ResourcePack *pack)
{
	std::list<std::string> listFiles = pack->ListFiles();

	if(pack->Loaded())
	{
		if(listFiles.empty())
		{
			std::cout << "No files to list." << std::endl;
		}
		else
		{
			for(auto &f : listFiles)
			{
				std::cout << f << std::endl;
			}
		}
	}
	else
	{
		std::cout << "No files to list." << std::endl;
	}
}

void Remove(olc::ResourcePack *pack, const std::string &sFilename)
{
	if(pack->RemoveFile(sFilename))
	{
		std::cout << sFilename << " has been removed." << std::endl;
	}
	else
	{
		std::cout << sFilename << " does not exist." << std::endl;
	}
	
}

void Rename(olc::ResourcePack *pack, const std::string &src, const std::string &dest)
{
	if(!pack->Loaded())
	{
		std::cout << "ERROR: pack is not loaded." << std::endl;
		return;
	}

	if(!pack->FileExists(src))
	{
		std::cout << "ERROR: " << src << " does not exist." << std::endl;
		return;
	}

	if(pack->FileExists(dest))
	{
		std::cout << "ERROR: " << dest << " already exists." << std::endl;
		return;
	}
	
	pack->RenameFile(src, dest);
	std::cout << src << " > " << dest << std::endl;

}

void usage(const std::string &message = "")
{
	if(!message.empty())
	{
		std::cout << "Syntax Error:" << std::endl << std::endl;
		std::cout << "  " << message << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Usage:	olcPack [PACK FILE] [PACK KEY] COMMAND [file/s]" << std::endl << std::endl;
	std::cout << "An archive for olc::PixelGameEngine Resource Packs" << std::endl << std::endl;
	std::cout << "Commands" << std::endl;
	std::cout << "  add         Add files to the pack" << std::endl;
	std::cout << "  help        Show this menu" << std::endl;
	std::cout << "  list        List files in the pack" << std::endl;
	std::cout << "  remove      Remove files from the pack" << std::endl;
	std::cout << "  rename      Rename files within the pack" << std::endl;

	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	bool bChanged = false;

	std::list<std::string> listArgs;
	std::string sFilename, sKey;

	for(int i = 1; i < argc; i++)
		listArgs.push_back(argv[i]);
	
	if(listArgs.size() < 3)
		usage();
	
	// get filename from args
	sFilename = listArgs.front();
	listArgs.pop_front();

	// get key from args
	sKey = listArgs.front();
	listArgs.pop_front();

	olc::ResourcePack *pack = new olc::ResourcePack();
	pack->LoadPack(sFilename, sKey);

	// ADD
	if(listArgs.front().compare("add") == 0)
	{
		listArgs.pop_front();

		if(listArgs.empty())
			usage("add [FILES]...");

		for(auto &f : listArgs)
			Add(pack, f);

		bChanged = true;
	}
	
	// HELP
	if(listArgs.front().compare("help") == 0)
	{
		usage();
	}

	// LIST
	if(listArgs.front().compare("list") == 0)
	{
		List(pack);
	}

	// REMOVE
	if(listArgs.front().compare("remove") == 0)
	{
		listArgs.pop_front();

		if(listArgs.empty())
			usage("remove [FILES]...");

		for(auto &f : listArgs)
			Remove(pack, f);
		
		bChanged = true;
	}

	// RENAME
	if(listArgs.front().compare("rename") == 0)
	{
		listArgs.pop_front();

		if(listArgs.size() != 2)
			usage("rename [SOURCE] [DESTINATION]");

		std::string src = listArgs.front();
		listArgs.pop_front();

		std::string dest = listArgs.front();
		listArgs.pop_front();

		Rename(pack, src, dest);

		bChanged = true;
	}

	// save changes
	if(bChanged)
		pack->SavePack(sFilename, sKey);

	return 0;
}
