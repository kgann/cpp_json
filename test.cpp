#include "./include/json.h"
#include <iostream>
using namespace std;

int main(){
  JSON lead("{\"rent_roll_id\":\"4eef4878528b20bedf000001\",\"client_id\":\"4eeb5694528b207096000002\",\"management_co_id\":6024,\"start_date\":\"2011-07-01\",\"end_date\":\"2011-07-31\"}");
  JSON lessee("{\"first_name\":\"Wanchao\",\"last_name\":\"Gao\",\"state\":\"Atlanta\",\"phone_1\":\"(678) 643-9781\",\"phone_2\":null,\"phone_3\":null,\"email\":\"wanchao.gao@gmail.com\",\"move_date\":\"7/1/11\",\"property_id\":\"88386\",\"lessee_source\":\"Internet-AMLI.com\",\"lm_client_id\":\"4eeb5694528b207096000002\",\"rent_roll_id\":\"4eef4878528b20bedf000001\"}");
  try {
    cout << "Lead = " << std::endl;
    cout << lead.get("rent_roll_id") << endl;
    cout << lead.get("client_id") << endl;
    cout << lead.get("start_date") << endl;
    cout << lead.get("end_date") << endl;

    cout << std::endl << std::endl;
    cout << "Lessee = " << std::endl;
    cout << lessee.get("first_name") << endl;
    cout << lessee.get("last_name") << endl;
    cout << lessee.get("state") << endl;
    cout << lessee.get("phone_1") << endl;
    cout << lessee.get("phone_2") << endl;
    cout << lessee.get("phone_3") << endl;
    cout << lessee.get("email") << endl;
    cout << lessee.get("move_date") << endl;
    cout << lessee.get("property_id") << endl;
    cout << lessee.get("lessee_source") << endl;
    cout << lessee.get("lm_client_id") << endl;
    cout << lessee.get("rent_roll_id") << endl;
  } catch (string& message){
    cout << message << endl;
  }
  return 0;
}