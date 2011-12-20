#include "./include/json.h"
#include <vector>
#include <sstream>
#include <string>

JSON::JSON(std::string json){
  this->json = json;
  parse();
}

JSON::~JSON(){}

void JSON::parse(){
  std::vector<std::string> elements;
  std::string json(this->json);

  json = strip(json, '{');
  json = strip(json, '}');

  std::istringstream iss(json);
  std::string token;
  while(getline(iss, token, ',')){
    elements.push_back(token);
  }
  int i;
  for(i = 0; i < elements.size(); i++){
    std::string ele, key, value;
    size_t position;
    ele = elements[i];
    position = ele.find_first_of(':');
    key = strip(ele.substr(0, position), '"');
    value = strip(ele.substr(position+1, ele.size()), '"');
    this->json_map[key] = value;
  }
}

std::string JSON::strip(std::string s, char c){
  size_t first, last;
  first = s.find_first_of(c);
  last = s.find_last_of(c);
  if(first == s.length() - 1) first = -1;
  return s.substr(first+1, last-1);
}

std::string JSON::getJSON(){
  return this->json;
}

std::string JSON::get(std::string key) {
  if (this->json_map.find(key) == this->json_map.end()) {
    throw "'" + key + "'" + " is not a valid key!";
  } else {
    return this->json_map[key];
  }
}