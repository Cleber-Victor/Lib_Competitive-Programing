int main(){
	string l, t;
	vector<string> st(10);
	while(getline(cin, l)){
		t = l;
		for(auto c : l)
			if(c == '{') st.push_back(""); else
			if(c == '}') t = st.back() + l, st.pop_back();
		cout << getHash(t) + " " + l + "\n";
		st.back() += t + "\n";
	}
}