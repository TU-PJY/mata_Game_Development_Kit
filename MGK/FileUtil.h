#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Setting.h"
#include "tinyxml/tinyxml.h"
#include "cryptopp/aes.h" 
#include "cryptopp/filters.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <cctype>
using namespace CryptoPP;

enum D_Type { 
	DATA_TYPE_DIGIT,
	DATA_TYPE_STRING 
};

struct FileData {
	std::string CategoryName;
	std::string DataName;
	int DataType;
	float DigitValue;
	std::string StringValue;
};

using DataSet = std::vector<FileData>;


// write and read
class FileUtil {
private:
	std::string FilePathStr{};
	std::filesystem::path FilePath{};
	TiXmlDocument Doc{};
	TiXmlElement* Root{};
	
	DataSet DataListBuffer{};

	bool FileExist{};

public:
	void Init(std::string FolderName, std::string FileName, DataSet List);
	void UpdateDigitData(std::string CategoryName, std::string DataName, float Value);
	void UpdateStringData(std::string CategoryName, std::string DataName, std::string Value);
	float LoadDigitData(std::string CategoryName, std::string DataName);
	std::string LoadStringData(std::string CategoryName, std::string DataName);
	void ResetData();
	void Release();

private:
	void SetupData();
	void CheckDataVersion();
	void UpdateDataVersion(float VersionValue);
	void CreateDec(float VersionValue);
	void AddRoot(std::string RootName);
	void AddCategory(std::string CategoryName);
	void AddDigitData(std::string CategoryName, std::string DataName, float Value);
	void AddStringData(std::string CategoryName, std::string DataName, std::string Value);
	void WriteDigitData(TiXmlElement* CategoryVar, std::string DataName, float Value);
	void WriteStringData(TiXmlElement* CategoryVar, std::string DataName, std::string Value);
	float GetDigitData(TiXmlElement* CategoryVar, std::string DataName);
	std::string GetStringData(TiXmlElement* CategoryVar, std::string DataName);
	TiXmlElement* FindRoot();
	TiXmlElement* FindCategory(std::string CategoryName);
	std::string FileUtil::FindData(std::string CategoryName, std::string DataName);
	bool LoadDataFile(std::string FileName);
	void UpdateDataFile();
	std::string Encrypt(const std::string& PlainText, const byte Key[], const byte IV[]);
	std::string Decrypt(const std::string& CipherText, const byte Key[], const byte IV[]);
};