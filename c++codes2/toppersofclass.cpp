#include<iostream>
#include<map>
#include<algorithm>
#include <iterator>
using namespace std;
int main()
 {
	multimap<int ,int> marksmap;
	int x,no_elements,value,no_toppers,i;
	cin>>x;
	while(x--)
	{
	    cin>>no_elements;
	    for(i=0;i<no_elements;i++)
	         {
	             cin>>value;
	            // marksmap[i]=value;
	            marksmap.insert(std::pair<int,int>(value,i));
	         }
	        // marksmap.reverse();
	         
	    cin>>no_toppers;
	    i=0;
	    std::map<int, int>::reverse_iterator it = marksmap.rbegin();

	// Iterate over the map using Iterator till beginning.
	while ((it != marksmap.rend())&&i<no_toppers) {
		// Accessing KEY from element pointed by it.
		int c=0,x;
		int word = it->first;
         if ((marksmap.count(word)>1)&&word!=x)
           {   no_toppers=no_toppers+marksmap.count(word)-1;
                 x=word;
//             c=marksmap.count(word);
//             i=i-c/2+2;
           }
		// Accessing VALUE from element pointed by it.
		int count = it->second;

		std::cout << word<<":" <<count<<"\t";

		// Increment the Iterator to point to next entry
//		if(c>=2)
//		{
//		i=i-(c-1);
//		}
		it++;i++;
	}
	    
	    cout<<"\n";
	}
	return 0;
}
