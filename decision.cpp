#include<iostream>
#include<map>     //map is included so that we can make use of it which is in standard library.
#include<string> //string is included so that we can make use of it which is in standard library.

using namespace std;
 
typedef map<int, string> maps; //we are assigning an alternate name for the existing data type map.
int key;   //in the map data type we are taking integer data type as the key.
string value;//in the map data type we are taking string data type as the value.
int numb;
int n;//n is the number of data points which are present in the data set.


class animals
// we define a class named animals which contains the data records and the functions which can be performed on the available data set
{
  public:
        int cold_count;//number of cold blooded animals
        int warm_count;//number of wram blooded animals
        int birth_yes;//number of animals which gives birth
        int birth_no;//number of animals which doesen't give birth
        int aquatic_yes;//number of animals which are aquatic
        int aquatic_no;//number of animals which are not aquatic
        int aerial_yes;//number of animals which are aerial
        int aerial_no;//number of animals which are not aerial
        
        map <int, int> body_temperature,gives_birth,aquatic,aerial,legs,hibernates;
        maps name,label;
  //we declare the variables name,body_temperature.. of the type maps.
  public:
         void input(int n,map<int, string> &mapn);
         void input(int n,map<int, int> &mapn);
         //it is an input function to read the values into the map for the further reference
         void print(map<int, string> &mapn);
         //it is the function which prints the key-value pairs of the map
         int gini_count(map <int,int>&m1, map<int,string>&m2,int count,int i,string s);
};

class mammals : public animals
// we define a class named mammals which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
  int mammal_cold_count;//number of cold blooded mammals
  int mammal_warm_count;//number of wram blooded mammals
};
void animals::input(int n,map<int, string>&mapn)
//this is the definition of the function which is present in the class animals for reading the input data set into the map
{
  for(int i=1;i<=n;i++)
 {

  cin >> key;//key is read from the keyboard
  cin >> value;//value is read from the keyboard
  mapn[key]=value;//key-value pairs are stored in the map
  
 }
}
void animals::input(int n,map<int, int>&mapn)
//this is the definition of the function which is present in the class animals for reading the input data set into the map
{
  for(int i=1;i<=n;i++)
 {

  cin >> key;//key is read from the keyboard
  cin >> numb;//value is read from the keyboard
  mapn[key]=numb;//key-value pairs are stored in the map
  
 }
}
void animals::print(map<int, string> &mapn)
//this is the definition of the function which is present in the class animals for printing the key value pairs which are presen in the map.
{
  for(map <int,string> ::iterator it=mapn.begin();it!=mapn.end();it++)
  //here we make use of iterator for iterating through the map,the function .begin() gives the beginning 
  //address of the element and similarly .end() gives the address of the last element,later we increment 
  //the iterator it.  
  {
  cout<<"\n"<<(*it).first<<"     "<<(*it).second;
  //to print the key value pairs with the help of address obtained from the iterators,here first 
  //refers to key and the second refers to the value in the map. 
  }  
  cout<<"\n";
}
int animals::gini_count(map <int,int>&m1,map<int,string>&m2,int count,int i,string s)
{
   for(map<int,int>::iterator it1=m1.begin();it1!=m1.end();it1++)
   {
     for(map<int,string>::iterator it2=m2.begin();it2!=m2.end();it2++)
     {
       if((*it1).second==i&&(*it2).second==s) //may be warm or yes cndition//if 1 was found
       {
        count+=1;
       }
     }
   }
   return count;
}
int main()
{
 cout<<"enter the value of n";
 //here n is the number of data points which are present in the data set.
 cin>>n;
 animals m;
 m.input(n,m.name);
 m.input(n,m.body_temperature);
 m.input(n,m.gives_birth);
 m.input(n,m.aquatic);
 m.input(n,m.aerial);
 m.input(n,m.legs);
 m.input(n,m.hibernates);
 m.input(n,m.label);
 m.print(m.name);
 //m.print(body_temperature);
 //m.print(gives_birth);
// m.print(aquatic);
 //m.print(aerial);
 //m.print(legs);
 //m.print(hibernates);
 //m.print(label);
 mammals mam;
 mam.mammal_warm_count=0;
 mam.mammal_cold_count=0;
 mam.mammal_warm_count=m.gini_count(m.body_temperature,m.label,m.warm_count,1,"mammal");
 mam.mammal_cold_count=m.gini_count(m.body_temperature,m.label,m.cold_count,0,"mammal");
 cout<<mam.mammals_warm_count;
 cout<<mam.mammals_warm_count
 return(0); 
}
