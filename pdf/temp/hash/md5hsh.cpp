@DE3 @string getHash(string s){
@909 @	ofstream ip("temp.cpp"); ip << s; ip.close();
@EE9 @	system("g++ -E -P -dD -fpreprocessed ./temp.cpp | tr -d '[:space:]' | md5sum > hsh.temp");
@CEF @	ifstream fo("hsh.temp"); fo >> s; fo.close();
@A15 @	return s.substr(0, 3);
@17A @}
@    @
@E8D @int main(){
@973 @	string l, t;
@3DA @	vector<string> st(10);
@C61 @	while(getline(cin, l)){
@54F @		t = l;
@242 @		for(auto c : l)
@F11 @			if(c == '{') st.push_back(""); else
@2F0 @			if(c == '}') t = st.back() + l, st.pop_back();
@C33 @		cout << getHash(t) + " " + l + "\n";
@1ED @		st.back() += t + "\n";
@D1B @	}
@B65 @}
