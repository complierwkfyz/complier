#include<iostream>
#include<map>
#include<set>
typedef std::set<unsigned> nfa_state_set;
nfa_state_set s1;
expand(s1);
static int id=0;
typedef std::map<nfa_state_set,unsigned> dfa_map;
dfa_map b;
dfa_map a;
b=insert(s1,id);
a=insert(s2,id);
id++;



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
