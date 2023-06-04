#include <iostream>
#include <string>
using namespace std;
struct dictionary {
	struct node
	{
		bool isWord;
		node* next[26];
		node()
		{
			isWord = false;
			for (int i = 0; i < 26; i++)
				next[i] = nullptr;
		}
	};
	struct Trie
	{

		node* root;
		Trie() { root = nullptr; }
		void insert(string str)
		{
			if (!root)
				root = new node;
			node* location = root;
			for (int i = 0; i < str.length(); i++)
			{
				int num = str[i] - 'a';
				if (location->node::next[num] == nullptr)
				{
					location->node::next[num] = new node;
				}
				location = location->node::next[num];
			}
			location->isWord = true;
		}
		bool search(string str)
		{
			node* location = root;
			for (int i = 0; i < str.length(); i++)
			{
				int num = str[i] - 'a';
				if (location->next[num] == nullptr)
					return false;
				location = location->next[num];
			}
			return location->isWord;
		}
	};
};
int main()
{
	setlocale(LC_ALL, "");
	string str1;
	bool start = true;

	dictionary::Trie trie;
	
	trie.insert("привет");
	trie.insert("пока");
	trie.insert("молодец");
	trie.insert("классно");
	trie.insert("хорошо");
	trie.insert("здравствуйте");
	trie.insert("нет");
	trie.insert("да");
	while (start) {
		cout << "¬ведите часть слова" << endl;
	cin >> str1;
	cout<<trie.search(str1);
	
}
  return 0;
}





























/*template<typename X, typename Y > class MyPair
{
private:
	X val;
	Y value;
public:
	MyPair() = default;
	MyPair(X x, Y y): val(x), value(y){}
	void getMax( X val,  Y value)
	{
		if (val > value)
		{
	     cout << val << endl;
		}
		 cout << value << endl;
	}
	

};


int main()
{
	MyPair<int, int>a;
	a.getMax(563, 654);
	MyPair<float, float>b;
	b.getMax(56.5, 98);
	MyPair<string, string>c;
	c.getMax("Artem", "Genius");
	
	
	
	return 0;
}*/