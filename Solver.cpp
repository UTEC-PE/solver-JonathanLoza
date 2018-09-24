#include <iostream>
#include <map>
#include <cmath>
#include "queue.h"
#include "stack.h"

using namespace std;
string masmenos(string x){
  char *str=&x[0];
  string answer="";
  int cont=0;
  while (*str!='\0') {
    if(*str==45)
      cont++;
    str++;
  }
  if(cont%2==0)
    answer='+';
  else{
    answer='-';
  }
  return answer;
};

int transform(char *str){
  std::map<string, int> map{{"+",2},{"-",2},{"*",3},{"/",3},{"^",4}};
  Stack<string> stack;
  Queue<string> queue;
  string acum="";
  string temp="";
  while(*str != '\0'){
    if(*str<58 && *str>47){

      while(*str<58 && *str>47){
        acum+=*str;
        str++;
        if(*str==46){
          acum+=*str;
          str++;
        }
      }str--;
      queue.push(acum);
    }
    if(*str==42 || *str==43 || *str==47 || *str==94 || *str==45){
      if(*str==45 || *str==43){
        while (*str==43 || *str==45) {
          acum+=*str;
          str++;
        }
        str--;
        acum=masmenos(acum);
      }
      acum=*str;
      if(!stack.empty()){
        while (!stack.empty() &&  map[stack.get()]>=map[acum] && acum!="(") {
          temp=stack.get();
          stack.pop();
          queue.push(temp);
        }
      }
      stack.push(acum);
    }
    if(*str==40){
      acum=*str;
      stack.push(acum);
    }
    if(*str==41){
      while(stack.get()!="("){
        temp=stack.get();
        stack.pop();
        queue.push(temp);
      }
      stack.pop();
    }
    acum="";
    str++;
  }
  while (!stack.empty()) {
    temp=stack.get();
    stack.pop();
    queue.push(temp);
  }
  queue.print();
  int size=queue.size();
  for(int i=0;i<size;i++){
    if(!(queue.get()=="+" || queue.get()=="-" || queue.get()=="*" || queue.get()=="/" || queue.get()=="^")){
        if(queue.get()!="")
          stack.push(queue.get());
    }
    else{
      if(queue.get()=="+"){
        //cout<<"suma"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=y+x;
        stack.push(to_string(z));
      }
      else if(queue.get()=="-"){
        //cout<<"resta"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=y-x;
        stack.push(to_string(z));
      }
      else if(queue.get()=="*"){
        //cout<<"multi"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=y*x;
        stack.push(to_string(z));
      }
      else if(queue.get()=="/"){
        //cout<<"division"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=y/x;
        stack.push(to_string(z));
      }
      else if(queue.get()=="^"){
        //cout<<"potencia"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=pow(y,x);
        stack.push(to_string(z));
      }
    }
    queue.pop();
  }
  stack.print();
};
