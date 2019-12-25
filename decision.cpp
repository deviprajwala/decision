#include<iostream>
#include<map>     //map is included so that we can make use of it which is in standard library.
#include<string> //string is included so that we can make use of it which is in standard library.


using namespace std;
 
typedef map<int, string> maps; //we are assigning an alternate name for the existing data type map.
int key;   //in the map data type we are taking integer data type as the key.
string value;//in the map data type we are taking string data type as the value.
int numb;
int n;//n is the number of data points which are present in the data set.
int label_num;//label_num is the number of class_labels which are present in the data set.
string s[10];
float a1,a2,b1,b2,c1,c2,d1,d2,e1,e2;

class animals
// we define a class named animals which contains the data records and the functions which can be performed on the available data set
{
  public:
       
        int id;
        map <int, int> body_temperature,gives_birth,aquatic,aerial,legs,hibernates;
        maps name,label;
  //we declare the variables name,body_temperature.. of the type maps.
  public:
         void input(int n,map<int, string> &mapn);
         void input(int n,map<int, int> &mapn);
         //it is an input function to read the values into the map for the further reference
         void print(map<int, string> &mapn);
         //it is the function which prints the key-value pairs of the map
         int gini_count1(map <int,int>&m1, map<int,string>&m2,int count,int i,string s);
         float gini_count2(map <int,int>&m1,map<int,string>&m2);
         float gini_count3();
         int square(int a);
         
         
};

class mammals : public animals
// we define a class named mammals which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 public:
  
  
};
class reptiles : public animals
// we define a class named reptiles which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 public:
  
  
};
class fish : public animals
// we define a class named fish which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 public:
  
  
  
};
class amphibian : public animals
// we define a class named amphibian which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 public:
  
  
};
class bird : public animals
// we define a class named bird which is publically inherited from the class animals which contains the data records and the functions which can be performed on the available data set and also functions and data define in the class animals are also available
{
 
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
int animals::gini_count1(map <int,int>&m1,map<int,string>&m2,int count,int i,string s)
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
float animals::gini_count2(map <int,int>&m1,map<int,string>&m2)
{
   float attribute_yes_label1=0,attribute_yes_label2=0,attribute_yes_label3=0,attribute_yes_label4=0;
   float attribute_yes_label5=0,attribute_no_label1=0,attribute_no_label2=0,attribute_no_label3=0;
   float attribute_no_label4=0,attribute_no_label5=0;
   int i=1;
   float gini;

   attribute_yes_label1=gini_count1(m1,m2,attribute_yes_label1,1,s[i]);
   attribute_no_label1=gini_count1(m1,m2,attribute_no_label1,0,s[i]);
   i++;


   attribute_yes_label2=gini_count1(m1,m2,attribute_yes_label2,1,s[i]);
   attribute_no_label2=gini_count1(m1,m2,attribute_no_label2,0,s[i]);
   i++;


   attribute_yes_label3=gini_count1(m1,m2,attribute_yes_label3,1,s[i]);
   attribute_no_label3=gini_count1(m1,m2,attribute_no_label3,0,s[i]);
   i++;


   attribute_yes_label4=gini_count1(m1,m2,attribute_yes_label4,1,s[i]);
   attribute_no_label4=gini_count1(m1,m2,attribute_no_label4,0,s[i]);
   i++;


   attribute_yes_label5=gini_count1(m1,m2,attribute_yes_label5,1,s[i]);
   attribute_no_label5=gini_count1(m1,m2,attribute_no_label5,0,s[i]);
   i++;
 


   a1=attribute_yes_label1;
   a2=attribute_no_label1;
   b1=attribute_yes_label2;
   b2=attribute_no_label2;
   c1=attribute_yes_label3;
   c2=attribute_no_label3;
   d1=attribute_yes_label4;
   d2=attribute_no_label4;
   e1=attribute_yes_label5;
   e2=attribute_no_label5;
   
   gini=gini_count3();
   return gini;

}

float animals::gini_count3()
{
  float v1,v2,x1,x2,yes_total,no_total,yes_totals,no_totals,total,gini;
  
  yes_total=a1+b1+c1+d1+e1;
  no_total=a2+b2+c2+d2+e2;

  total=yes_total+no_total;

  a1=square(a1);
  a2=square(a2);
  b1=square(b1);
  b2=square(b2);
  c1=square(c1);
  c2=square(c2);
  d1=square(d1);
  d2=square(d2);
  e1=square(e1);
  e2=square(e2);
  yes_totals=square(yes_total);
  no_totals=square(no_total);
 
  v1=1-(a1/yes_totals)-(b1/yes_totals)-(c1/yes_totals)-(d1/yes_totals)-(e1/yes_totals);

  v2=1-(a2/no_totals)-(b2/no_totals)-(c2/no_totals)-(d2/no_totals)-(e2/no_totals);
  
  
 
  gini=((yes_total/total)*v1)+((no_total/total)*v2);
  cout<<gini;
  return gini;
  
}

int animals::square(int a)
{
   return a*a;
}
int main()
{
 string str;
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
 cin>>label_num;
 for(int i=1;i<=label_num;i++)
 {
   cin>>str;
   s[i]=str;
  }
 mammals mam;
/*here mam is an object of class mammals.we repeatedly call gini count function to get the values which are defined in the inherited class mammals which is inherite from class animals publically.These values are needed for the calculation of the gini index so that effecient splitting can be performed
*/
 reptiles rep;
 gini=mam.gini_count2(m.body_temperature,m.label);
 gini=mam.gini_count2(m.gives_birth,m.label);
 gini=mam.gini_count2(m.aquatic,m.label);
 return(0); 
}
