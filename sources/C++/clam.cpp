#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
class CLAM { 
public:
	CLAM(std::string path, std::string customKey = "$C**M$"){
      this->path = path;
    }
	inline void writeToProperty(std::string Property, std::string Replacement);
	inline std::string readFromProperty(std::string Property);
	inline void createSubset(); 
	inline void createProperty(std::string Property, std::string Replacement);
private:
	std::string path;
	int CLAMfileversion;
	std::string customKey;
	//.clam
	inline void clam_writeToProperty(std::string Property, std::string Replacement);
	inline std::string clam_readFromProperty(std::string Property)
	//.clam2
	inline std::string clam2_getCustomKey();
};
//ALL
/*
*
*
*
*
*
*
*
*/
std::string CLAM::readFromProperty(std::string Property){
  std::ifstream file(this->path);
  std::string text;
  std::string returnstring = "";
   while (std::getline(file, text)){
	if (text.substr(0, text.find(": "))== Property){
		returnstring = text.erase(0, Property.length() + 1);
    }

     
   }
  if (returnstring == ""){
  	returnstring = "Error";
  }
  return returnstring;
}
void CLAM::writeToProperty(std::string Property, std::string Replacement){
	std::ifstream file(this->path);
  	std::string text, pre, post, changed;    
    int preOrPost = 0;
    while (std::getline(file, text)){
      if (text.substr(0, text.find(": ")) == Property){
         preOrPost= 1;
        continue;
      }
      else if ( preOrPost == 0){
        pre += text + "\n";
      }
      else if (preOrPost == 1){
        post += text + "\n";
      }
	
    }
    changed = pre + Property + ": " + Replacement + "\n" + post;
    file.close();
    std::remove(this->path.c_str());
    std::ofstream file2(this->path);
    file2 << changed;
    file2.close();
}
void CLAM::createProperty(std::string Property, std::string Replacement){
  	std::ofstream file(this->path);
    file << Property + ": " + Value + "\n";
    file.close();
}







//CLAM
/*
*
*
*
*
*
*/




//CLAM2
/*
*
*
*
*
*
*
*/
