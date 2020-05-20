/*
	+-------------------------------------------------------------+
	|         OneLoneCoder Resource Pack Utility v1.00            |
	|  "When it's not good enough, make it better!!!" - Moros1138 |
	+-------------------------------------------------------------+

	What is this?
	~~~~~~~~~~~~~
	olcPack is a command-line utility for adding, and managing
	files into the virtual filesystem used by the olcPixelGameEngine
*/

#include "olcResourcePack.h"
#include <algorithm>
#include <cstdio>

void Add(olc::ResourcePack *pack, const std::string &sFilename)
{
	if(pack->AddFile(sFilename))
	{
		std::cout << sFilename << " added." << std::endl;
		return;
	}

	std::cout << "ERROR: " << sFilename << " not added. File not found." << std::endl;
}

void License()
{
	std::cout << "	License (OLC-3)" << std::endl;
	std::cout << "	~~~~~~~~~~~~~~~" << std::endl  << std::endl;

	std::cout << "	Copyright 2018 - 2020 OneLoneCoder.com" << std::endl << std::endl;

	std::cout << "	Redistribution and use in source and binary forms, with or without modification," << std::endl;
	std::cout << "	are permitted provided that the following conditions are met:" << std::endl << std::endl;

	std::cout << "	1. Redistributions or derivations of source code must retain the above copyright" << std::endl;
	std::cout << "	notice, this list of conditions and the following disclaimer." << std::endl << std::endl;

	std::cout << "	2. Redistributions or derivative works in binary form must reproduce the above" << std::endl;
	std::cout << "	copyright notice. This list of conditions and the following	disclaimer must be" << std::endl;
	std::cout << "	reproduced in the documentation and/or other materials provided with the distribution." << std::endl << std::endl;

	std::cout << "	3. Neither the name of the copyright holder nor the names of its contributors may" << std::endl;
	std::cout << "	be used to endorse or promote products derived from this software without specific" << std::endl;
	std::cout << "	prior written permission." << std::endl << std::endl;

	std::cout << "	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS	\"AS IS\" AND ANY" << std::endl;
	std::cout << "	EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES" << std::endl;
	std::cout << "	OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT" << std::endl;
	std::cout << "	SHALL THE COPYRIGHT	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT," << std::endl;
	std::cout << "	INCIDENTAL,	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED" << std::endl;
	std::cout << "	TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR" << std::endl;
	std::cout << "	BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN" << std::endl;
	std::cout << "	CONTRACT, STRICT LIABILITY, OR TORT	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN" << std::endl;
	std::cout << "	ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF" << std::endl;
	std::cout << "	SUCH DAMAGE." << std::endl << std::endl;
}

// Thanks MaGetzUb
const char* FormatSize(std::size_t size)
{
	static char buf[256] = {};

	static const char *suffix[] = {"B", "KB", "MB", "GB", "TB"};

	size_t mul = 0, index = 0;

	if(size >= 0) mul = 1, index = 0;
	if(size >= 1024) mul = 1024, index = 1;
	if(size >= 1048576) mul = 1048576, index = 2;
	if(size >= 1073741824) mul = 1073741824, index = 3;
	if(size >= 1099511627776) mul = 1099511627776, index = 4;

	sprintf(buf, "%ld%s", (size / mul), suffix[index]);

	return buf; 
}

void List(olc::ResourcePack *pack, bool asc = true)
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
			std::printf("Size\t | Filename\n");
			std::printf("------------------------------------------\n");
			
			listFiles.sort([pack, asc](const std::string &a, const std::string &b){
				
				olc::ResourceBuffer rb_a = pack->GetFileBuffer(a);
				olc::ResourceBuffer rb_b = pack->GetFileBuffer(b);

				if(asc)
					return rb_a.vMemory.size() < rb_b.vMemory.size();

				return rb_a.vMemory.size() > rb_b.vMemory.size();

			});
			
			for(auto &f : listFiles)
			{
				olc::ResourceBuffer rb = pack->GetFileBuffer(f);
				std::printf("%s\t | %s\n", FormatSize(rb.vMemory.size()), f.c_str());
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
	if(pack->RemoveFile(sFilename) == olc::rcode::OK)
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
	std::cout << "  license     Show the OneLoneCoder license" << std::endl;
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

	std::printf("\nolcPack (olcPixelGameEngine Resource Pack Utility)\n\n");
	std::printf("Managing: %s\n\n", sFilename.c_str());
	
	
	if(listArgs.front().compare("add") == 0) // ADD
	{
		listArgs.pop_front();

		if(listArgs.empty())
			usage("add [FILES]...");

		for(auto &f : listArgs)
			Add(pack, f);

		bChanged = true;
	}
	else if(listArgs.front().compare("help") == 0) // HELP
	{
		usage();
	}
	else if(listArgs.front().compare("license") == 0) // LICENSE
	{
		License();
	}
	else if(listArgs.front().compare("list") == 0) // // LIST
	{
		if(listArgs.size() >= 2)
		{
			listArgs.pop_front();

			if(listArgs.front().compare("asc") == 0)
			{
				List(pack);
			}

			if(listArgs.front().compare("desc") == 0)
			{
				List(pack, false);
			}
		}
		else
		{
			List(pack);
		}
	}
	else if(listArgs.front().compare("remove") == 0) // REMOVE
	{
		listArgs.pop_front();

		if(listArgs.empty())
			usage("remove [FILES]...");

		for(auto &f : listArgs)
			Remove(pack, f);
		
		bChanged = true;
	}
	else if(listArgs.front().compare("rename") == 0) // RENAME
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
	else
	{
		usage();
		return 1;
	}
	
	// save changes
	if(bChanged)
		pack->SavePack(sFilename, sKey);

	return 0;
}
