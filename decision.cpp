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
        int leg_no;//number of animals which do not have legs
        int leg_yes;//number of animals which has legs
        int hibernates_yes;//number of animals which do not hibernate
        int hibernates_no;//number of animals which  hibernate
        
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
 public:
  int mammal_cold_count;//number of cold blooded mammals
  int mammal_warm_count;//number of wram blooded mammals
  int mammal_birth_yes;//number of mammals which gives birth
  int mammal_birth_no;//number of mammals which doesen't give birth
  int mammal_aquatic_yes;//number of mammals which are aquatic
  int mammal_aquatic_no;//number of mammals which are not aquatic
  int mammal_aerial_yes;//number of mammals which are aerial
  int mammal_aerial_no;//number of mammals which are not aerial
  int mammal_leg_no;//number of mammals which do not have legs
  int mammal_leg_yes;//number of mammals which has legs
  int mammal_hibernates_yes;//number of mammals which do not hibernate
  int mammal_hibernates_no;//number of mammals which  hibernate
  
  
};
class reptiles : public animals
// we define a class named reptiles which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 public:
  int reptile_cold_count;//number of cold blooded reptiles
  int reptile_warm_count;//number of wram blooded reptiles
  int reptile_birth_yes;//number of reptiles which gives birth
  int reptile_birth_no;//number of reptiles which doesen't give birth
  int reptile_aquatic_yes;//number of reptiles which are aquatic
  int reptile_aquatic_no;//number of reptiles which are not aquatic
  int reptile_aerial_yes;//number of reptiles which are aerial
  int reptile_aerial_no;//number of reptiles which are not aerial
  int reptile_leg_no;//number of reptiles which do not have legs
  int reptile_leg_yes;//number of reptiles which has legs
  int reptile_hibernates_yes;//number of reptiles which do not hibernate
  int reptile_hibernates_no;//number of reptiles which  hibernate
  
  
};
class fish : public animals
// we define a class named fish which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 public:
  int fish_cold_count;//number of cold blooded fishes
  int fish_warm_count;//number of wram blooded fishes
  int fish_birth_yes;//number of fishes which gives birth
  int fish_birth_no;//number of fishes which doesen't give birth
  int fish_aquatic_yes;//number of fishes which are aquatic
  int fish_aquatic_no;//number of fishes which are not aquatic
  int fish_aerial_yes;//number of fishes which are aerial
  int fish_aerial_no;//number of fishes which are not aerial
  int fish_leg_no;//number of fishes which do not have legs
  int fish_leg_yes;//number of fishes which has legs
  int fish_hibernates_yes;//number of fishes which do not hibernate
  int fish_hibernates_no;//number of fishes which  hibernate
  
  
};
class amphibian : public animals
// we define a class named amphibian which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 public:
  int amphibian_cold_count;//number of cold blooded amphibians
  int amphibian_warm_count;//number of wram blooded amphibians
  int amphibian_birth_yes;//number of amphibians which gives birth
  int amphibian_birth_no;//number of amphibians which doesen't give birth
  int amphibian_aquatic_yes;//number of amphibians which are aquatic
  int amphibian_aquatic_no;//number of fishes which are not aquatic
  int amphibian_aerial_yes;//number of fishes which are aerial
  int amphibian_aerial_no;//number of fishes which are not aerial
  int amphibian_leg_no;//number of fishes which do not have legs
  int amphibian_leg_yes;//number of fishes which has legs
  int amphibian_hibernates_yes;//number of fishes which do not hibernate
  int amphibian_hibernates_no;//number of fishes which  hibernate
  
  
};
class fish : public animals
// we define a class named fish which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 public:
  int fish_cold_count;//number of cold blooded fishes
  int fish_warm_count;//number of wram blooded fishes
  int fish_birth_yes;//number of fishes which gives birth
  int fish_birth_no;//number of fishes which doesen't give birth
  int fish_aquatic_yes;//number of fishes which are aquatic
  int fish_aquatic_no;//number of fishes which are not aquatic
  int fish_aerial_yes;//number of fishes which are aerial
  int fish_aerial_no;//number of fishes which are not aerial
  int fish_leg_no;//number of fishes which do not have legs
  int fish_leg_yes;//number of fishes which has legs
  int fish_hibernates_yes;//number of fishes which do not hibernate
  int fish_hibernates_no;//number of fishes which  hibernate
  
  
};
void animals::input(int n,map<int,string>&mapn)
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
void animals::print(map<int,string> &mapn)
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
//here in this function we count the number of data points that satisfy the condition and label which is needed in future for the calculation of gini index
{
   map<int,int>::iterator it1=m1.begin();
   //we map iterator of the first map to the first element the map i,e the it1 contains the address of  
   //the first element in the map 
   for(map<int,string>::iterator it2=m2.begin();it2!=m2.end();it2++)
   //it2 is the iterator which we use for the second map, we initialise it to the starting address and 
   //the we increment it unit it points to the last element of the map
   {
     if(((*it1).first==(*it2).first)&&((*it1).second==i)&&((*it2).second==s))
     //we compare the keys in each of the map which is (*it1).first==(*it2).first,then we check whether 
     //(*it2).second satifies the condition i,they are checked for equality,similarly we check for 
     //the equality of label and the string (*it2).second==s
     {
       count+=1;
     }
     it1++;
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
 //m.print(aquatic);
 //m.print(aerial);
 //m.print(legs);
 //m.print(hibernates);
 m.print(m.label);
 mammals mam;
 mam.mammal_warm_count=0;
 mam.mammal_cold_count=0;
 mam.mammal_warm_count=m.gini_count(m.body_temperature,m.label,mam.mammal_warm_count,1,"mammal");
 mam.mammal_cold_count=m.gini_count(m.body_temperature,m.label,mam.mammal_cold_count,0,"mammal");
 cout<<mam.mammal_warm_count<<"  ";
 cout<<mam.mammal_cold_count;
 return(0); 
}
