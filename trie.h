#include <bits/stdc++.h>


const int ALPHABET_SIZE = 26;

using namespace std;

struct trie_node
{
	struct trie_node* child[ALPHABET_SIZE];
	bool end_of_word;
};

struct trie_node* create_node()
{
	struct trie_node* t = new trie_node;
	
	t->end_of_word=false;
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		t->child[i]=NULL;
	}
	
	return t;
}

void insert(struct trie_node* root, string key)
{
	struct trie_node* t=root;
	
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(t->child[index]==NULL)
		{
			t->child[index]=create_node();
		}
		t=t->child[index];
	}

}
bool search(struct trie_node* root, string key)
{
	struct trie_node* t=root;
	
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(t->child[index]==NULL)
		{
			return false;
		}
		t=t->child[index];
	}
	return (t!=NULL&&t->end_of_word);
	
}

bool is_empty(trie_node* root)
{
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		if(root->child[i]!=NULL)
			return false;
	}
	return true;
}

trie_node* remove(trie_node* root, string key, int depth =0)
{
	if(root==NULL)
		return NULL;
	
	if(depth==key.size())
	{
		if(root->end_of_word==true)
		{
			root->end_of_word=false;
			
		}
			
			
		if(is_empty(root))
		{
			delete(root);
			root=NULL;
			
		}	
			
		return root;
	}
	
	int index=key[depth]-'a';
	root->child[index]=remove(root->child[index],key,depth+1);
	
	if(is_empty(root)&&root->end_of_word==false)
	{
		delete(root);
		root=NULL;
	}
	
	return root;
}
