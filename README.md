# decision tree
The program is mainly based on developing a classification model which can serve as a tool to distinguish between objects of different 
classes.WE build a classification model from an input data set, this program is mainly based on the data set of vertebrates.Decision tree is 
one of the classifier which is employed in the program.Here we make use of gini index to obtain the best test attribute and splitting of 
the data is done based on the attribute with lowest gini index value.
Once the data is splitted it is checked for stopping condition. Stopping condition is satisfied if all the objects in the class have same 
labels if "yes" then that becomes the leaf node and terminates, if "not" then further splitting takes place and the calculation of gini 
index splitting based on the test attribute continues until it satisfies the stopping condition.
