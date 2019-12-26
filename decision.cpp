#include<iostream>
#include<map>     //map is included so that we can make use of it which is in standard library.
#include<string> //string is included so that we can make use of it which is in standard library.
#include<vector>//vector is included so that we can make use of it which is in standard library.
#include<set> //set is included so that we can make use of it which is in standard library.
#include<stdlib.h>
using namespace std;
 
typedef map<int, string> maps; //we are assigning an alternate name for the existing data type map.
int key;   //in the map data type we are taking integer data type as the key.
string value;//in the map data type we are taking string data type as the value.
int numb;
int n;//n is the number of data points which are present in the data set.
int label_num;//label_num is the number of class_labels which are present in the data set.
int attribute_num;//attribute_num is the number of attributes which are present in the data set.
string attribut[10];//array of strings which contain the names of the attributes.
string labe[10];//array of labels which contain the names of the attributes.
float a1,a2,b1,b2,c1,c2,d1,d2,e1,e2;//these values are needed for the calculation of gini index
float gini;//it holds the calculated value of gini index 


struct node
//here we define a structure named node which contains the elements such as test condition,label,id and pointers lchild and rchild which is necessary for the fulfillment of the tree growth algorithm.
{
 char test_condition[10];
 char label[10];
 struct node *lchild;
 struct node *rchild;
 int condition_id;
};


struct data_record
//here we define a structure named data record which contains all the map elements of the data records on which the necessary operations has to be performed.
{
  map <int, int> body_temperature,gives_birth,aquatic,aerial,legs,hibernates;
  maps name,label;
};
typedef struct node node;

node getnode()
//function which allocates space for the node.
{
  node *x;
  x=(node *)malloc(sizeof(node));
  return *x;
}

class animals
// we define a class named animals which contains the data records and the functions which can be performed on the available data set
{
  public:
          set< string> attribute;//set of strings which are the names of the attributes.
          struct data_record data;//structure in which the data records are present
          
 
  public:
         void set_init();//to initial lise the set with the names of attributes.

         void input(int n,map<int, string> &mapn);//function to read the data record.

         void input(int n,map<int, int> &mapn);
         //it is an input function to read the values into the map for the further reference

         void print(map<int, string> &mapn);
         //it is the function which prints the key-value pairs of the map

         int gini_count1(map <int,int>&m1, map<int,string>&m2,int count,int i,string s);
         //in this function we count the number of data points that satisfy the condition and label 
         //which is needed in future for the calculation of gini index

         float gini_count2(map <int,int>&m1,map<int,string>&m2);
         //here in this function we calculate the values which are needed for the calculation of the    
         //gini index for each of the label and attribute combination.

         float gini_count3();
         //here in this function we actully calculate the value of the gini index with the help of the 
         //values which was calculated earlier.

         int square(int a);
         //this function just squares a number and returns it.

         int get_best_split();
         //in this function we get the gini index for each of the attribute by calling a function
         //gini_count2 and get the best attribute for splitting which is the one with least value 

         int stopping_condition();
         //this function checks for the stopping condition which is satisfied if all the data points 
         //in the data set has the same label

         struct data_record split_record(int i,int attribute,struct data_record data);
         //here  the data record is splitted as per the attribute test condition so that further 
         //checking can be done to split further or make it as a leaf node.

         map<int,int>splitting(map <int,int>&m1,map<int,string>&m2,string check,int i);
         map<int,int>get_key_similar(map <int,int>&m1,int key[15],int k);
};


void animals::set_init()
{
   for(int i=1;i<=label_num;i++)
   {
      attribute.insert(attribut[i]);
   }
   /*for(set<string>::iterator it=attribute.begin();it!=attribute.end();it++)
   {
     cout<<(*it)<<"  ";
   }
   */
}
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
       //count is incremented
     }
     it1++;
     //iterator it1 is incremented for further calculation.
   }
   return count;
  
}
float animals::gini_count2(map <int,int>&m1,map<int,string>&m2)
//here in this function we calculate the values which are needed for the calculation of the gini index
//for each of the label and attribute combination.
{
   float attribute_yes_label1=0,attribute_yes_label2=0,attribute_yes_label3=0,attribute_yes_label4=0;
   float attribute_yes_label5=0,attribute_no_label1=0,attribute_no_label2=0,attribute_no_label3=0;
   float attribute_no_label4=0,attribute_no_label5=0;
   int i=1;
   float gini;

   attribute_yes_label1=gini_count1(m1,m2,attribute_yes_label1,1,labe[i]);
   attribute_no_label1=gini_count1(m1,m2,attribute_no_label1,0,labe[i]);
   i++;
   //count of data points in attribute for each of the possible combination in label1 is calculated

   attribute_yes_label2=gini_count1(m1,m2,attribute_yes_label2,1,labe[i]);
   attribute_no_label2=gini_count1(m1,m2,attribute_no_label2,0,labe[i]);
   i++;
   //count of data points in attribute for each of the possible combination in label2 is calculated

   attribute_yes_label3=gini_count1(m1,m2,attribute_yes_label3,1,labe[i]);
   attribute_no_label3=gini_count1(m1,m2,attribute_no_label3,0,labe[i]);
   i++;
   //count of data points in attribute for each of the possible combination in label3 is calculated

   attribute_yes_label4=gini_count1(m1,m2,attribute_yes_label4,1,labe[i]);
   attribute_no_label4=gini_count1(m1,m2,attribute_no_label4,0,labe[i]);
   i++;
   //count of data points in attribute for each of the possible combination in label4 is calculated

   attribute_yes_label5=gini_count1(m1,m2,attribute_yes_label5,1,labe[i]);
   attribute_no_label5=gini_count1(m1,m2,attribute_no_label5,0,labe[i]);
   i++;
   //count of data points in attribute for each of the possible combination in label5 is calculated


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
   //values are assigned to the variables which defined as global so that it can be easily assecced by
   //by the function which is called below   

   gini=gini_count3();
   return gini;

}

float animals::gini_count3()
//here in this function we actully calculate the value of the gini index with the help of the values 
//which was calculated earlier. 
{
  float v1,v2,x1,x2,yes_total,no_total,yes_totals,no_totals,total,gini;
  
  yes_total=a1+b1+c1+d1+e1;//number of values which satisfies the condition.
  no_total=a2+b2+c2+d2+e2;//number of values which does not satisfy the condition.

  total=yes_total+no_total;//total number points in the data set.

  a1=square(a1);//the values are squared as per the requirement for the calulation of gini index
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
  //it is based n the formula 1-summation((p^2)/(t^2))

  v2=1-(a2/no_totals)-(b2/no_totals)-(c2/no_totals)-(d2/no_totals)-(e2/no_totals);
  //it is based n the formula 1-summation((p^2)/(t^2))
  
 
  gini=((yes_total/total)*v1)+((no_total/total)*v2);
  //final value of gini index which calculated and returned

  return gini;
  //the gini index is returned to the calling function.  
}

int animals::square(int a)
//this function just squares a number and returns it.
{
   return a*a;
}

int animals::get_best_split()
//in this function we get the gini index for each of the attribute by calling a function gini_count2 and
//get the best attribute for splitting which is the one with least value 
{
 vector<float> v(6);
 //the value of gini index of attributes is stored in vector 
 int i=1;
 float min;
 int attribute=1;
 v[i++]=gini_count2(data.body_temperature,data.label);
 v[i++]=gini_count2(data.gives_birth,data.label);
 v[i++]=gini_count2(data.aquatic,data.label);
 v[i++]=gini_count2(data.aerial,data.label);
 v[i++]=gini_count2(data.legs,data.label);
 v[i]=gini_count2(data.hibernates,data.label);
 
 min=v[1];
 for(int i=2;i<v.size();i++)
 {
    if(v.at(i)<min)//we check fo rthe value which has the least value
    {
      min=v.at(i);
      attribute=i;
    } 
 }
 return attribute;
 //the attribute with the least value is returned
}

/*node tree_growth(set<string>attribute,struct data)
{
   struct data_record left_record,right_record;
   *node rooot,right_child,left_child;
   int attribute;

   s=stopping_condition();//function to check the stopping conition
   if(s->stopping==1)//if the stopping condition is met i.e all data points have same label
   {
     node *leaf;
     leaf=getnode();
     strcpy(leaf->label,s->data.label);//leaf node is created and label is assigned
     return *leaf;
   }
   else
   {
   
   *root=getnode();
   v=find_best_split(head);// v is the condition id which is returned by best split function
   left_record=split_record(1,v,data);//spilt the the records which satisfies the condition
   right_record=split_record(0,v,data);//spilt the the records which does not satisfy the condition
   right_child=tree_growth(head_right);//check foe further growth in child nodes
   left_child=tree_growth(head_left);
   root->rchild=right_child;//assign the child nodes to the root
   root->lchild=left_child;
   }
return root;
}
*/
int animals::stopping_condition()
//this function checks for the stopping condition which is satisfied if all the data points in the data
//set has the same label
{
  map<int,string>::iterator it2=data.label.begin();
  //iterator it2 has the address of the first element in the map label which is present in the structure 
  //named data
  string test=(*it2).second;
  //test contains the label of the first element of the map
  for(map<int,string>::iterator it2=data.label.begin();it2!=data.label.end();it2++)
  //map iterated with the help of iterator it2 and checked for equalities of the label if any of the 
  //element fails to satisfy the condition then -1 is returned
  {
      if(test!=(*it2).second)
      {
        return -1;//false
      }       
  }
  return 1;
  //if the stopping condition is satisfied then 1 is returned i.e all the labels are similar
}
struct data_record animals::split_record(int i,int attribute,struct data_record data)
//here  the data record is splitted as per the attribute test condition so that further checking can be 
//done to split further or make it as a leaf node
{
   struct data_record required_data;
   string check;
   //based on gini index if attribute 1 has best split then splitting is done based on that attribute
   if(attribute==1)
   {
     check=attribut[1];
   }
   required_data.body_temperature=splitting(data.body_temperature,data.label,check,i);

   //based on gini index if attribute 2 has best split then splitting is done based on that attribute
   if(attribute==2)
   {
     check=attribut[2];
   }
   required_data.body_temperature=splitting(data.gives_birth,data.label,check,i);

   //based on gini index if attribute 3 has best split then splitting is done based on that attribute
   if(attribute==3)
   {
     check=attribut[3];
   }
   required_data.body_temperature=splitting(data.aquatic,data.label,check,i);

   //based on gini index if attribute 4 has best split then splitting is done based on that attribute
   if(attribute==4)
   {
     check=attribut[4];
   }
   required_data.body_temperature=splitting(data.aerial,data.label,check,i);

   //based on gini index if attribute 5 has best split then splitting is done based on that attribute
   if(attribute==5)
   {
     check=attribut[5];
   }
   required_data.body_temperature=splitting(data.legs,data.label,check,i);

   //based on gini index if attribute 6 has best split then splitting is done based on that attribute
   if(attribute==6)
   {
     check=attribut[6];
   }
   required_data.body_temperature=splitting(data.hibernates,data.label,check,i);

  return required_data;
  //the structure data which contains the records after splitting is returned
}


map<int,int> animals :: splitting(map <int,int>&m1,map<int,string>&m2,string check,int i)
{
   struct required_data;
   int key[15],k=1;
   map<int,int> body_temperature;
   if(check==attribut[1])
   {
   for(map<int,int>::iterator it=data.body_temperature.begin();it!=data.body_temperature.end();it++)
    {
      if((*it).second==i)
      {
          key[k]=(*it).first;
          k++;
      }
    }
   }
   body_temperature=get_key_similar(data.body_temperature,key,k);
   
 
 return body_temperature;
}
map<int,int> animals::get_key_similar(map <int,int>&m1,int key[15],int k)
{
  int i=1,ke,v;
  map<int,int> ret;
  label:
  {
  for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++)
    {
      if((*it).first==key[i])
      {
          ke=key[i];
          v=(*it).second;
          ret[ke]=v;
      }
    }
   }
    while(i!=k)
    {
      i++;
      goto label;
    }
  return ret;
}
int main()
{
 string str;
 //cout<<"enter the value of n";
 //here n is the number of data points which are present in the data set.
 cin>>n;
 animals m;
 m.input(n,m.data.name);
 m.input(n,m.data.body_temperature);
 m.input(n,m.data.gives_birth);
 m.input(n,m.data.aquatic);
 m.input(n,m.data.aerial);
 m.input(n,m.data.legs);
 m.input(n,m.data.hibernates);
 m.input(n,m.data.label);
 m.print(m.data.name);
 //m.print(body_temperature);
 //m.print(gives_birth);
 //m.print(aquatic);
 //m.print(aerial);
 //m.print(legs);
 //m.print(hibernates);
 //m.print(m.label);
 
 cin>>label_num;
 for(int j=1;j<=label_num;j++)
 {
   cin>>str;
   labe[j]=str;
  }
 m.set_init();
 cin>>attribute_num;
 for(int i=1;i<=attribute_num;i++)
 {
   cin>>str;
   attribut[i]=str;
  }
 //mammals mam;
/*here mam is an object of class mammals.we repeatedly call gini count function to get the values which are defined in the inherited class mammals which is inherite from class animals publically.These values are needed for the calculation of the gini index so that effecient splitting can be performed
*/
 //attribute=m.get_best_split();
 /*struct data_record si;
 si=m.split_record(1,1,m.data);*/
 struct data_record required_data;
 required_data.body_temperature=m.splitting(m.data.body_temperature,m.data.label,"body_temperature",1);
 return(0); 
}
