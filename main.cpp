#include "Solver.cpp"

using namespace std;

string variables(char* str){
  string x="";
  string value;
  map<char,string> variables;
  while (*str!='\0') {
    if((*str>65 && *str<91) || (*str>96 && *str<123)){
      auto search=variables.find(*str);
      if(search!=variables.end()){
        x+=search->second;
      }else{
        cout<<"Ingrese el valor de "<<*str<<endl;
        getline(cin,value);
        variables[*str]=value;
        x+=value;
      }
    }else{
      x+=*str;
    }
    str++;
  }
  std::cout<<x<<endl;
  return x;
};

void menu() {
      //system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      //char *str="7/4*((a+b)^4*a)+3";
      char *str="12.45-+-+45.7*3-5";
      //char *str="9+24/(4-3)";
      string newx=variables(str);
      str=&newx[0];
      transform(str);
}

int main(int argc, char const *argv[]) {
    menu();
    //cout << "\nPress enter to continue ...";
    //cin.get();
    return EXIT_SUCCESS;
}
