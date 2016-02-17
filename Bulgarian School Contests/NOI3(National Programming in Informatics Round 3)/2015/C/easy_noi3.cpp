#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

bool p, f;
char ch;
int r0, n, op1, op2, a;
string cod[maxN], operand1[maxN], operand2[maxN];

int strToInt(string s)
{
	int ans = 0;

	for(int i = 0; i < s.size(); i++)
	{
		ans = 10 * ans + (s[i] - '0');
	}

	return ans;
}
void ifRecurse(int ind, int r[]);
int solve(int par);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>r0;
	for(int i = 0; i < n; i++)
	{
		cin>>cod[i];
		if(cod[i] != "CALL" && cod[i] != "RET" && cod[i] != "ENDIF")
		{
			cin.get(ch);
			getline(cin, operand1[i], ',');
			cin>>operand2[i];
		}
		else if(cod[i] != "ENDIF")
		{
			cin.get(ch);
			cin>>operand1[i];
		}
	}

	int ans = solve(r0);
	if(f) cout<<'*'<<endl;
	else cout<<ans<<endl;
	return 0;
}

int solve(int par)
{
	a++;
	if(a == 10000) 
	{
		f = true;
		return 0;
	}
	if(f) return 0;
	int r[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	r[0] = par;

	for(int i = 0; i < n; i++)
	{
		if(cod[i] != "CALL" && cod[i] != "RET")
		{
			if(operand1[i][0] != 'R') op1 = strToInt(operand1[i]);
			else op1 = r[operand1[i][1] - '0'];
			if(operand2[i][0] != 'R') op2 = strToInt(operand2[i]);
			else op2 = r[operand2[i][1] - '0'];

			if(cod[i] == "MOV") r[operand1[i][1] - '0'] = op2;
			else if(cod[i] == "ADD") r[operand1[i][1] - '0'] = (r[operand1[i][1] - '0'] + op2) % 1000;
			else if(cod[i] == "SUB") 
			{
				r[operand1[i][1] - '0'] -= op2;
				if(r[operand1[i][1] - '0'] < 0) r[operand1[i][1] - '0'] += 1000;
			}
			else if(cod[i] == "MUL") r[operand1[i][1] - '0'] = (r[operand1[i][1] - '0'] * op2) % 1000;
			else if(cod[i] == "DIV")
			{
				if(op2 == 0) r[operand1[i][1] - '0'] = 0;
				else r[operand1[i][1] - '0'] /= op2;
			}
			else if(cod[i] == "MOD")
			{
				if(op2 == 0) r[operand1[i][1] - '0'] = 0;
				else r[operand1[i][1] - '0'] %= op2;
			}
			else if(cod[i] == "IFEQ")
			{
				if(op1 == op2) ifRecurse(i + 1, r);
				while(cod[i] != "ENDIF") i++;
			}
			else if(cod[i] == "IFNEQ")
			{
				if(op1 != op2) ifRecurse(i + 1, r);
				while(cod[i] != "ENDIF") i++;
			}
			else if(cod[i] == "IFG")
			{
				if(op1 > op2) ifRecurse(i + 1, r);
				while(cod[i] != "ENDIF") i++;
			}
			else if(cod[i] == "IFL")
			{
				if(op1 < op2) ifRecurse(i + 1, r);
				while(cod[i] != "ENDIF") i++;
			}
			else if(cod[i] == "IFGE")
			{
				if(op1 >= op2) ifRecurse(i + 1, r);
				while(cod[i] != "ENDIF") i++;
			}
			else if(cod[i] == "IFLE")
			{
				if(op1 <= op2) ifRecurse(i + 1, r);
				while(cod[i] != "ENDIF") i++;
			}

			if(p) 
			{
				p = false;
				return r[9];
			}
		}
		else
		{
			if(operand1[i][0] != 'R') op1 = strToInt(operand1[i]);
			else op1 = r[operand1[i][1] - '0'];

			if(cod[i] == "RET") return op1;
			else r[9] = solve(op1);
		}
	}

	return r[9];
}
void ifRecurse(int ind, int r[])
{
	p = false;
	for(int i = ind; i < n; i++)
	{
		if(cod[i] != "CALL" && cod[i] != "RET")
		{
			if(operand1[i][0] != 'R') op1 = strToInt(operand1[i]);
			else op1 = r[operand2[i][1] - '0'];
			if(operand2[i][0] != 'R') op2 = strToInt(operand2[i]);
			else op2 = r[operand2[i][1] - '0'];

			if(cod[i] == "MOV") r[operand1[i][1] - '0'] = op2;
			else if(cod[i] == "ADD") r[operand1[i][1] - '0'] = (r[operand1[i][1] - '0'] + op2) % 1000;
			else if(cod[i] == "SUB") 
			{
				r[operand1[i][1] - '0'] -= op1;
				if(r[operand1[i][1] - '0'] < 0) r[operand1[i][1] - '0'] += 999;
			}
			else if(cod[i] == "MUL") r[operand1[i][1] - '0'] = (r[operand1[i][1] - '0'] * op2) % 1000;
			else if(cod[i] == "DIV")
			{
				if(op2 == 0) r[operand1[i][1] - '0'] = 0;
				else r[operand1[i][1] - '0'] /= op2;
			}
			else if(cod[i] == "MOD")
			{
				if(op2 == 0) r[operand1[i][1] - '0'] = 0;
				else r[operand1[i][1] - '0'] /= op2;
			}
			else if(cod[i] == "IFEQ")
			{
				if(op1 == op2) ifRecurse(i + 1, r);
				else
				{
					while(cod[i] != "ENDIF") i++;
				}
			}
			else if(cod[i] == "IFNEQ")
			{
				if(op1 != op2) ifRecurse(i + 1, r);
				else
				{
					while(cod[i] != "ENDIF") i++;
				}
			}
			else if(cod[i] == "IFG")
			{
				if(op1 > op2) ifRecurse(i + 1, r);
				else
				{
					while(cod[i] != "ENDIF") i++;
				}
			}
			else if(cod[i] == "IFL")
			{
				if(op1 < op2) ifRecurse(i + 1, r);
				else
				{
					while(cod[i] != "ENDIF") i++;
				}
			}
			else if(cod[i] == "IFGE")
			{
				if(op1 >= op2) ifRecurse(i + 1, r);
				else
				{
					while(cod[i] != "ENDIF") i++;
				}
			}
			else if(cod[i] == "IFLE")
			{
				if(op1 <= op2) ifRecurse(i + 1, r);
				else
				{

					while(cod[i] != "ENDIF") i++;
				}
			}
		}
		else
		{
			if(operand1[i][0] != 'R') op1 = strToInt(operand1[i]);
			else op1 = r[operand1[i][1] - '0'];

			if(cod[i] == "RET") 
			{
				r[9] = op1;
				p = true;
				break;
			}
			else r[9] = solve(op1);
		}
	}
}
