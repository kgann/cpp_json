#include "json.h"
#include <iostream>
using namespace std;

int main(){
  try {
    JSON lead("{\"rent_roll_id\":\"4eef4:8785,28b20bedf000001\",\"client_id\":\"4eeb5694528b207096000002\",\"management_co_id\":6024,\"start_date\":\"2011-07-01\",\"end_date\":\"2011-07-31\"}");
    JSON lessee("{\"first_name\":\"latrisha\",\"last_name\":\"Roberson\",\"state\":null,\"phone_1\":null,\"phone_2\":\"7707124190\",\"phone_3\":null,\"email\":\"im2blessed2stress@yahoo.com\",\"move_date\":\"2011-07-22\",\"property_id\":\"19\",\"lessee_source\":\"Directional Signage\",\"lm_client_id\":\"4ef1eb545677dc2f64000002\",\"rent_roll_id\":\"4ef245d4528b20125600000b\"}");

    cout << "Lead = "             << lead.getJSON() << endl << endl;
    cout << "rent_roll_id = "     << lead.get("rent_roll_id") << endl;
    cout << "client_id = "        << lead.get("client_id") << endl;
    cout << "management_co_id = " << lead.get("management_co_id") << endl;
    cout << "start_date = "       << lead.get("start_date") << endl;
    cout << "end_date = "         << lead.get("end_date") << endl;

    cout << endl << endl;
    cout << "Lessee = "        << lessee.getJSON() << endl << endl;
    cout << "first_name = "    << lessee.get("first_name") << endl;
    cout << "last_name = "     << lessee.get("last_name") << endl;
    cout << "state = "         << lessee.get("state") << endl;
    cout << "phone_1 = "       << lessee.get("phone_1") << endl;
    cout << "phone_2 = "       << lessee.get("phone_2") << endl;
    cout << "phone_3 = "       << lessee.get("phone_3") << endl;
    cout << "email = "         << lessee.get("email") << endl;
    cout << "move_date = "     << lessee.get("move_date") << endl;
    cout << "property_id = "   << lessee.get("property_id") << endl;
    cout << "lessee_source = " << lessee.get("lessee_source") << endl;
    cout << "lm_client_id = "  << lessee.get("lm_client_id") << endl;
    cout << "rent_roll_id = "  << lessee.get("rent_roll_id") << endl;
  } catch (string& error){
    cout << error << endl;
  }
  return 0;
}
