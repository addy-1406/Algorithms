#include<iostream>
#include<vector>
using namespace std;

struct node {
	string data;
	struct node* left;
	struct node* right;
};

struct node* newNode(string data){
	struct node* var = new node;
	var->data = data;
	var->left = NULL;
	var->right = NULL;
	return var;
}

int evaluate(struct node* ptr){
	if(ptr->left == NULL && ptr->right == NULL){
		string temp = ptr->data;
		int res = 0;
		for(auto x:temp){
			res = res*10 + (x-'0');
		}
		return res;
	}
	if(ptr->data == "+") return (evaluate(ptr->left) + evaluate(ptr->right));
	if(ptr->data == "-") return (evaluate(ptr->left) - evaluate(ptr->right));
	if(ptr->data == "*") return (evaluate(ptr->left) * evaluate(ptr->right));
	if(ptr->data == "/") return (evaluate(ptr->left) / evaluate(ptr->right));
	return 0;
}

void infix(struct node* ptr){
	if(ptr->left == NULL && ptr->right == NULL){
		cout << ptr->data ;
		return;
	}
	infix(ptr->left);
	cout << " ";
	cout << ptr->data ;
	cout << " ";
	infix(ptr->right);
	return;
}

void prefix(struct node* ptr){
	if(ptr->left == NULL && ptr->right == NULL){
		cout << ptr->data ;
		return;
	}
	cout << ptr->data ;
	cout << " ";
	prefix(ptr->left);
	cout << " ";
	prefix(ptr->right);
	return;
}

void postfix(struct node* ptr){
	if(ptr->left == NULL && ptr->right == NULL){
		cout << ptr->data ;
		return;
	}
	postfix(ptr->left);
	cout << " ";
	postfix(ptr->right);
	cout << " ";
	cout << ptr->data ;
	return;
}


int main() {
	string s;
	cin >> s;
	int n = s.size();
	string tempnum = "";
	vector<struct node*> operand;
	vector<char> oper;
	int eval = 0;
	int i = 0;
	while(i < n){
		char ch = s[i];
		if(ch == '('){
			oper.push_back(ch);
		}
		else if(ch - '0' >= 0 && ch - '0' <= 9){
			while(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
				tempnum += s[i];
				i++;
			}
			node* leaf = newNode(tempnum);
			operand.push_back(leaf);
			tempnum = "";
			continue;
		}
		else if(ch == ')'){
			node* b = operand[operand.size() - 1];
			operand.pop_back();
			
			node *a = operand[operand.size() - 1];
			operand.pop_back();
			
			char operat = oper[oper.size() - 1];
			oper.pop_back();
			oper.pop_back();
			
			string z = "";
			z += operat;
			node* subtree = newNode(z);
			subtree->left = a;
			subtree->right = b;
			operand.push_back(subtree);
		}
		else{
			oper.push_back(ch);
		}
		i++;
	}	

	cout << "PREFIX : ";
	prefix(operand[0]);
	cout << "\n";
	cout << "INFIX : ";
	infix(operand[0]);
	cout << "\n";
	cout << "POSTFIX : ";
	postfix(operand[0]);
	cout << "\n";
	cout <<  "ANSWER : "<<evaluate(operand[0]) << "\n";

}
