#include <iostream>

#include "gfs.hpp"
#include "Path.hpp"

int main(int argc, char** argv)
{
#ifdef __linux__
	gfs::Path file("~/Code/GenFS/GenFS.txt");
#elif defined _WIN32
	gfs::Path file("G:/Code/bzHGTeditor/README.md");
#endif

	std::cout << std::boolalpha;
	std::cout << "file exists: " << file.exists() << '\n';
	std::cout << "filename: " << file.filename() << '\n';
	std::cout << "file name: " << file.name() << '\n';
	std::cout << "file ext: " << file.extension() << '\n';
	std::cout << "file parent: " << file.parent() << '\n';
	std::cout << "file last access: " << file.lastAccess().time_since_epoch().count() << '\n';
	std::cout << "file last modify: " << file.lastModify().time_since_epoch().count() << '\n';
	
	std::cout << "file type: ";
	switch(file.type())
	{
		case gfs::Path::Type::File:
			std::cout << "File\n";
			break;
		case gfs::Path::Type::Directory:
			std::cout << "Directory\n";
			break;
		case gfs::Path::Type::Character:
			std::cout << "Character\n";
			break;
		case gfs::Path::Type::Block:
			std::cout << "Block\n";
			break;
		case gfs::Path::Type::Pipe:
			std::cout << "Pipe\n";
			break;
		case gfs::Path::Type::SymLink:
			std::cout << "SymLink\n";
			break;
		case gfs::Path::Type::Socket:
			std::cout << "Socket\n";
			break;
		case gfs::Path::Type::Unknown:
			std::cout << "Unknown\n";
			break;
	}
	
	std::cout << "$HOME: " << gfs::userHome() << '\n';
	std::cout << "pwd: " << gfs::workingDir() << '\n';
	std::cout << "self path: " << gfs::selfPath() << '\n';
	
	gfs::Path sym("C:/Users/Alec/Desktop/Atom.lnk");
	
	std::cout << "sym: " << sym << '\n';
	std::cout << "sym exists: " << sym.exists() << '\n';
	std::cout << "sym ext: " << sym.extension() << '\n';
	std::cout << "sym parent: " << sym.parent() << '\n';
	std::cout << "sym target: " << gfs::readSymlink(sym) << '\n';
	
	std::cout << "sym type: ";
	switch(sym.type())
	{
		case gfs::Path::Type::File:
			std::cout << "File\n";
			break;
		case gfs::Path::Type::Directory:
			std::cout << "Directory\n";
			break;
		case gfs::Path::Type::Character:
			std::cout << "Character\n";
			break;
		case gfs::Path::Type::Block:
			std::cout << "Block\n";
			break;
		case gfs::Path::Type::Pipe:
			std::cout << "Pipe\n";
			break;
		case gfs::Path::Type::SymLink:
			std::cout << "SymLink\n";
			break;
		case gfs::Path::Type::Socket:
			std::cout << "Socket\n";
			break;
		case gfs::Path::Type::Unknown:
			std::cout << "Unknown\n";
			break;
	}
	
	gfs::Path dir("~/Documents");
	
	gfs::PathContents children = gfs::contents(dir);
	
	std::cout << "dir perms: " << std::oct << dir.permissions() << '\n';
	std::cout << "dir children:\n";
	for(auto& c : children)
		std::cout << c << '\n';
		
	gfs::Path newDir("~/Code/GenFS/test/");
	
	gfs::makeDir(newDir);
	
	std::cout << "newDir perms: " << std::oct << newDir.permissions() << '\n';
	
	return 0;
}
