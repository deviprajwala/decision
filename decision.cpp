#include<iostream>
#include<map>     //map is included so that we can make use of it which is in standard library.
#include<string> //string is included so that we can make use of it which is in standard library.
#include<vector>//vector is included so that we can make use of it which is in standard library.
#include<set> //set is included so that we can make use of it which is in standard library.
#include<stdlib.h>


using namespace std;
 
int key;   //in the map data type we are taking integer data type as the key.
string value;//in the map data type we are taking string data type as the value.
int numb;
int n;//n is the number of data points which are present in the data set.
int label_num;//label_num is the number of class_labels which are present in the data set.
int attribute_num;//attribute_num is the number of attributes which are present in the data set.
string labe[10];//array of labels which contain the names of the attributes.
string atributes[10];//array of strings which contain the names of the attributes.
float a1,a2,b1,b2,c1,c2,d1,d2,e1,e2;//these values are needed for the calculation of gini index
float gini;//it holds the calculated value of gini index 


struct node
//here we define a structure named node which contains the elements such as test condition,label,id and pointers lchild and rchild which is necessary for the fulfillment of the tree growth algorithm.
{
 string label;
 int id;
 struct node *lchild;//pointer to the left child
 struct node *rchild;//pointer to the right child
 struct node *parent;//pointer to the parent
 struct node *class_label;//pointer to the class label which is a leaf node
 
};


struct data_record
//here we define a structure named data record which contains all the map elements of the data records on which the necessary operations has to be performed.
{
  map <int, int> body_temperature,gives_birth,aquatic,aerial,legs,hibernates;
  map <int,string> name,label;
};


struct retur
//here we define a structure named retur which contains the elements such as label and id which is necessary for checking the stopping condition.
{
  string label;
  int id;
};

struct node *newnode(string label,int i)
//this structure is defined to get a node structure and assign the label to it make its pointers as null.
//this function is used when a node is not a leaf. 
{
  struct node *temp =  new struct node();
  temp->label = label;
  temp->id=i;
  temp->lchild = temp->rchild = NULL;
  return temp;
}

struct node *newnode1(string label,int i,struct node* root)
//this structure is defined to get a node structure and assign the label,class label to it make its pointers as null.This function is used when a node is a leaf.
 
{
  struct node *temp =  new struct node();
  temp->label = label;
  temp->id=i;
  temp->lchild = temp->rchild = NULL;
  root->class_label=temp;
  return temp;
}

struct node* insert(struct node* root,struct node* child,int id)
{
   struct node* par;
   //tree is empty,return a new node
  if (root == NULL) return root;

    //if tree is not empty find the proper place to insert new node
  if (id==1)
  {
   root->lchild  = child;
   child->parent=root;
  }
  else if(id==0)
  { 
  root->rchild = child;
  child->parent=root;
  }
  
return child;
//return the node pointer
}



class animals
// we define a class named animals which contains the data records and the functions which can be performed on the available data set
{
  public:
          string atribute[10];//array of strings which contain the names of the attributes.
          struct data_record data;//structure in which the data records are present
          
 
  public:
         struct node* tree_growth(string atribut[10],struct data_record data,struct node *root);
         //induction algorithm for the growth of the tree which performs the performance of the decision 
         //tree.
 
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

         int get_best_split(string atribute[10]);
         //in this function we get the gini index for each of the attribute by calling a function
         //gini_count2 and get the best attribute for splitting which is the one with least value 

         struct retur stopping_condition(struct data_record data);
         //this function checks for the stopping condition which is satisfied if all the data points 
         //in the data set has the same label

         struct data_record split_record(int i,int attri,struct data_record data,string atribute[10]);
         //here  the data record is splitted as per the attribute test condition so that further 
         //checking can be done to split further or make it as a leaf node.
         
         map<int,int>get_key_similar(map <int,int>&m1,int key[15],int k);
         map<int,string>get_key_similar2(map <int,string>&m1,int key[15],int k);
         //in this function we get an array of intergers which are the key values.Based on this key 
         //values we split the data record and return it to the splitting function.The map regarding 
         //each of the attribute is splitted and returned.

         struct data_record splitting(map <int,int>&m1,int i);
         //In this function we get the map of each of the attribute which are splitted as per the 
         //requirement we combine all these maps to a structure data_record and return it to the
         //  calling function.
         
         
         
};

struct node* animals::tree_growth(string atribute[10],struct data_record data,struct node* root)
//induction algorithm for the growth of the tree which performs the performance of the decision tree.
{
   struct data_record left_record,right_record;
   struct node* right_child;
   struct node* left_child;
   struct node* lpar;
   struct node* rpar;
   int v;
   retur s;
   s=stopping_condition(data);//function to check the stopping conition
    if(s.id==1)//if the stopping condition is met i.e all data points have same label
    {
     struct node* leaf;
     leaf = newnode1(s.label,100,root);//leaf node is created and label is assigned
     return leaf;
    }
    else
    {
     v=get_best_split(atribute);// v is the condition id which is returned by best split function
     left_record=split_record(1,v,data,atribute);//spilt the the records which satisfies the condition
     right_record=split_record(0,v,data,atribute);//spilt the the records which does not satisfy the 
                                                //condition
     
    
     left_child=newnode(atributes[v],1);//get a node for the left child
     right_child=newnode(atributes[v],0);//get a node for the right child
     lpar = insert(root,left_child,1);//insert a left child and get its parent
     rpar = insert(root,right_child,0);//insert a right child and get its parent

     left_child=tree_growth(atribute,left_record,lpar);
     right_child=tree_growth(atribute,right_record,rpar);//check for further growth in child nodes
    
    }
   
  
return root;
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
  float v1,v2,yes_total,no_total,yes_totals,no_totals,total,gini;
  
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

int animals::get_best_split(string atribute[10])
//in this function we get the gini index for each of the attribute by calling a function gini_count2 and
//get the best attribute for splitting which is the one with least value 
{
 vector<float> v(6);
 //the value of gini index of attributes is stored in vector 
 int i=1;
 float min;
 int attribute=1;
 if(atribute[i]!="null")//checks whether the data had already been split by this attribute1 or not
   {
   v[i]=gini_count2(data.body_temperature,data.label);
   }
 i++;
 if(atribute[i]!="null")//checks whether the data had already been split by this attribute2 or not
   {
   v[i]=gini_count2(data.gives_birth,data.label);
   }
 i++;
 if(atribute[i]!="null")//checks whether the data had already been split by this attribute3 or not
   {
   v[i]=gini_count2(data.aquatic,data.label);
   }
 i++;
 if(atribute[i]!="null")//checks whether the data had already been split by this attribute4 or not
   {
   v[i]=gini_count2(data.aerial,data.label);
   }
 i++;
 if(atribute[i]!="null")//checks whether the data had already been split by this attribute5 or not
   {
   v[i]=gini_count2(data.legs,data.label);
   }
 i++;
 if(atribute[i]!="null")//checks whether the data had already been split by this attribute6 or not
   {
   v[i]=gini_count2(data.hibernates,data.label);
   }
 i++;
 min=100;
 for(int j=1;j<v.size();j++)
 {
    if(v.at(j)<min&&v.at(j)!=0)//we check fo rthe value which has the least value
    {
      min=v.at(j);
      attribute=j;
    } 
 }
 i=1;
 return attribute;
 //the attribute with the least value is returned
}



struct retur animals::stopping_condition(struct data_record data)
//this function checks for the stopping condition which is satisfied if all the data points in the data
//set has the same label
{
  retur r;
  map<int,string>::iterator it2=data.label.begin();
  //iterator it2 has the address of the first element in the map label which is present in the structure 
  //named data
  if(data.label.size()>0)
  {
    string test=(*it2).second;
    r.label=test;
    //test contains the label of the first element of the map
    for(map<int,string>::iterator it2=data.label.begin();it2!=data.label.end();it2++)
   //map iterated with the help of iterator it2 and checked for equalities of the label if any of the 
   //element fails to satisfy the condition then -1 is returned
    {
      if(test!=(*it2).second)
      {
        r.id=-1;
        return r;//false
      }       
    }
  r.id=1;
  }
 
  return r;
  //if the stopping condition is satisfied then 1 is returned i.e all the labels are similar
}
struct data_record animals::split_record(int i,int attri,struct data_record data,string atribute[10])
//here  the data record is splitted as per the attribute test condition so that further checking can be 
//done to split further or make it as a leaf node
{
   data_record required_data;
   string check;
   
   //based on gini index if attribute 1 has best split then splitting is done based on that attribute
   if(attri==1)
   {
     atribute[1]="null";
     required_data=splitting(data.body_temperature,i);
   }
   
   //based on gini index if attribute 2 has best split then splitting is done based on that attribute
   else if(attri==2)
   {
     atribute[2]="null";
     required_data=splitting(data.gives_birth,i);
   }
   

   //based on gini index if attribute 3 has best split then splitting is done based on that attribute
   else if(attri==3)
   {
     atribute[3]="null";
     required_data=splitting(data.aquatic,i);
   }
   

   //based on gini index if attribute 4 has best split then splitting is done based on that attribute
   else if(attri==4)
   {
     atribute[4]="null";
     required_data=splitting(data.aerial,i);
   }
   

   //based on gini index if attribute 5 has best split then splitting is done based on that attribute
   else if(attri==5)
   {
     atribute[5]="null";
     required_data=splitting(data.legs,i);
   }
   

   //based on gini index if attribute 6 has best split then splitting is done based on that attribute
   else if(attri==6)
   {
     atribute[6]="null";
     required_data=splitting(data.hibernates,i);
   }
   

  return required_data;
  //the structure data which contains the records after splitting is returned
}


map<int,int> animals::get_key_similar(map <int,int>&m1,int key[15],int k)
//in this function we get an array of intergers which are the key values.Based on this key values we 
//split the data record and return it to the splitting function.The map regarding each of the attribute 
//is splitted and returned.The map contains intger both key as well as value.
{
  int i=1,ke,v;
  map<int,int> ret;
  label:
  {
  for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++)
  //we iterate through the map which is sent as an argument
    {
      if((*it).first==key[i])
      //if the elements of the array key are equal to the key value of the map which is sent as an 
      //argument then that corresponding key-value pair is inserted inta a map which is returned later
      {
          ke=key[i];//key of the map which is an integer
          v=(*it).second;//value of map which is an integer
          ret[ke]=v;
      }
    }
   }
    while(i!=k)
    {
      i++;//the value of i is incremented so that all the values present in the array key are compared
          //with the key values of the map
      goto label;
    }
  return ret;
}

map<int,string> animals::get_key_similar2(map <int,string>&m1,int key[15],int k)
//in this function we get an array of intergers which are the key values.Based on this key values we 
//split the data record and return it to the splitting function.The map regarding each of the attribute 
//is splitted and returned.The is combination of string and integer.
{
  int i=1,ke;
  string v;
  map<int,string> ret;
  label:
  {
  for(map<int,string>::iterator it=m1.begin();it!=m1.end();it++)
  //we iterate through the map which is sent as an argument
    {
      if((*it).first==key[i])
      //if the elements of the array key are equal to the key value of the map which is sent as an 
      //argument then that corresponding key-value pair is inserted inta a map which is returned later
      {
          ke=key[i];//key of the map which is an integer
          v=(*it).second;//value of map which is a string
          ret[ke]=v;
      }
    }
   }
    while(i!=k)
    {
      i++;//the value of i is incremented so that all the values present in the array key are compared
          //with the key values of the map
      goto label;
    }
  return ret;
}
struct data_record animals :: splitting(map <int,int>&m1,int i)
//In this function we get the map of each of the attribute which are splitted as per the requirement
//we combine all these maps to a structure data_record and return it to the calling function.
{
   data_record required_data;
   int key[15],k=1;
   
   for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++)
   //we iterate through the map which is sent as an argument
    {
      if((*it).second==i)
      //we chech whether the condition "i" of attribute is satisfied or not.If the condition is met the
      //key values of them are stored in an array
      {
          key[k]=(*it).first;
          k++;
      }
    }
  
   required_data.body_temperature=get_key_similar(data.body_temperature,key,k);
   //we get the map of body_temperature after splitting and is added to data_record

   required_data.gives_birth=get_key_similar(data.gives_birth,key,k);
   //we get the map of gives_birth after splitting and is added to data_record

   required_data.aquatic=get_key_similar(data.aquatic,key,k);
   //we get the map of aquatic after splitting and is added to data_record

   required_data.aerial=get_key_similar(data.aerial,key,k);
   //we get the map of aerial after splitting and is added to data_record

   required_data.legs=get_key_similar(data.legs,key,k);
   //we get the map of legs after splitting and is added to data_record

   required_data.hibernates=get_key_similar(data.hibernates,key,k);
   //we get the map of hibernates after splitting and is added to data_record

   required_data.name=get_key_similar2(data.name,key,k);
   //we get the map of name after splitting and is added to data_record

   required_data.label=get_key_similar2(data.label,key,k);
   //we get the map of label after splitting and is added to data_record

 return required_data;
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
 //m.print(m.data.name);
 //m.print(body_temperature);
 //m.print(gives_birth);
 //m.print(aquatic);
 //m.print(aerial);
 //m.print(legs);
 //m.print(hibernates);
 //m.print(m.label);
 
 cin>>label_num;//to get the number of labels
 for(int j=1;j<=label_num;j++)
 {
   cin>>str;
   labe[j]=str;//assigns the string value to the array
  }

 cin>>attribute_num;//to get the number of arrays
 for(int i=1;i<=attribute_num;i++)
 {
   cin>>str;
   m.atribute[i]=str;//assigns the value to the array
   atributes[i]=str;
   //cout<<atribute[i]<<"  "<<i;
  }

  //cout<<"enter the number of data set";
  int x;//number of data sets
  cin>>x;
  struct node *rooti;
  for(int i=0;i<x;i++)
  {
   if(i==0)
   {
    rooti=NULL;
    }
  
  rooti=newnode("start",100);//node is allocated
  rooti=m.tree_growth(m.atribute,m.data,rooti);//tree growth function is called
  }
   
   /*
   //cout<<rooti->label;
   //cout<<rooti->lchild->label<<"  ";
   //cout<<rooti->lchild->lchild->label<<"   ";
   //cout<<rooti->lchild->lchild->class_label->label<<"   ";
   //cout<<rooti->lchild->rchild->class_label->label<<"   ";
   //cout<<rooti->rchild->lchild->class_label->label<<"   ";//amphibian
   //cout<<rooti->rchild->rchild->rchild->class_label->label;//reptile
   //cout<<rooti->rchild->rchild->lchild->class_label->label;//fish
   */   

  /*these are redirected for the construction of the diagraph for the pictorial representation*/

   cout<<"digraph G {"<<"\n";
   cout<<rooti->label<<"->"<<rooti->lchild->label<<"yes"<<"\n";
   cout<<rooti->label<<"->"<<rooti->rchild->label<<"no"<<"\n";
   cout<<rooti->lchild->label<<"yes"<<"->"<<rooti->lchild->lchild->label<<"yes"<<"\n";
   cout<<rooti->lchild->label<<"yes"<<"->"<<rooti->lchild->rchild->label<<"no"<<"\n";
   cout<<rooti->lchild->lchild->label<<"yes"<<"->"<<rooti->lchild->lchild->class_label->label<<"\n";
   cout<<rooti->lchild->lchild->label<<"no"<<"->"<<rooti->lchild->rchild->class_label->label<<"\n";

   cout<<rooti->rchild->label<<"no"<<"->"<<rooti->rchild->lchild->label<<"yes"<<"\n";
   cout<<rooti->rchild->label<<"no"<<"->"<<rooti->rchild->rchild->label<<"no"<<"\n";

   cout<<rooti->rchild->lchild->label<<"yes"<<"->"<<rooti->rchild->lchild->class_label->label;
   
   cout<<"\n"<<rooti->rchild->rchild->label<<"no"<<"->";
   cout<<rooti->rchild->rchild->lchild->label<<"yes";
   cout<<"\n"<<rooti->rchild->rchild->label<<"no"<<"->";
   cout<<rooti->rchild->rchild->lchild->label<<"no"<<"\n";
   
   cout<<rooti->rchild->rchild->lchild->label<<"no"<<"->";
   cout<<rooti->rchild->rchild->lchild->class_label->label<<"\n";

   cout<<rooti->rchild->rchild->lchild->label<<"yes"<<"->";
   cout<<rooti->rchild->rchild->rchild->class_label->label<<"\n";


   cout<<rooti->rchild->rchild->rchild->class_label->label;
   cout<<"[ shape=rectangle]"<<"\n";
   cout<<rooti->rchild->rchild->lchild->class_label->label<<"\n";
   cout<<"[ shape=rectangle]"<<"\n";
   cout<<rooti->rchild->lchild->class_label->label<<"[ shape=rectangle]"<<"\n";
   cout<<rooti->lchild->lchild->class_label->label<<"[ shape=rectangle]"<<"\n";
   cout<<rooti->lchild->rchild->class_label->label<<"[ shape=rectangle]"<<"\n";
   cout<<"}";
   
 return(0); 
}
