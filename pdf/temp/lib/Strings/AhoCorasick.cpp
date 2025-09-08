@7CE @using ll = long long int;
@F79 @#define pll pair<long long, long long>
@0C1 @#define vi vector<int>
@358 @#define vll vector<long long>
@    @
@3C9 @struct node { // pode adicionar um contador de prefixos
@15E @  node* p = nullptr;
@05C @  node* nxt[26] = {};
@446 @  node* sl = nullptr; // suffix link
@63A @  node* ol = nullptr; // output link
@0AF @  int c;
@919 @  int idx = -1; // -1 indica que nao eh fim de palavra.
@FBA @  int prf_cnt =0;
@6D4 @};
@    @
@    @
@4BC @typedef node* trie;
@D41 @//trie root = new node();
@    @
@903 @void add(trie root ,const string& s, int pattern_idx) { // O(S)
@346 @  trie t = root;
@BF4 @  t->prf_cnt++;
@1CF @  for (int i = 0; i < s.size(); i++) {
@827 @    char c = s[i];
@9AE @    int v = c - 'a';
@AC9 @    if (!t->nxt[v]) {
@F90 @      trie son = new node();
@EB1 @      son->c = v;
@DAE @      son->p = t;
@B29 @      t->nxt[v] = son;
@5A9 @    }
@C80 @    t = t->nxt[v];
@BF4 @    t->prf_cnt++;
@C40 @  }
@    @
@38C @  t->idx = pattern_idx;
@F6F @}
@B47 @void buildLinks(trie root) { // O(L) L-> numero de nos
@    @
@EF5 @  root->sl = root;
@    @
@83D @  queue<trie> q;
@42F @  for(int i = 0; i < 26; i++) {
@280 @    if(root->nxt[i]) {
@A94 @      q.push(root->nxt[i]);
@FC8 @      root->nxt[i]->sl = root; // Filhos da raiz tem sl para a raiz
@9D3 @    }
@D8B @  }
@    @
@14D @  while (!q.empty()) {
@81D @    trie t = q.front();
@833 @    q.pop();
@    @
@1E1 @    for (int c = 0; c < 26; c++) {
@4B4 @      if (t->nxt[c]) {
@371 @        trie son = t->nxt[c];
@DD3 @        trie w = t->sl;
@516 @        while (w != root && !w->nxt[c]) {
@AA5 @          w = w->sl;
@6B6 @        }
@312 @        if (w->nxt[c]) {
@BE9 @          son->sl = w->nxt[c];
@6C5 @        } else {
@F0A @          son->sl = root;
@BB5 @        }
@    @
@D41 @        //LOGICA DO OUTPUT LINK
@D41 @        // Verifica se o no do suffix link eh o fim de uma palavra.
@D41 @        // Se for (idx != -1), o output link aponta para ele.
@D41 @        // Senao, herda o output link dele.
@C84 @        if (son->sl->idx != -1) {
@AF1 @          son->ol = son->sl;
@D2B @        } else {
@9C1 @          son->ol = son->sl->ol;
@E1A @        }
@    @
@F96 @        q.push(son);
@4F7 @      }
@9E8 @    }
@B93 @  }
@E75 @}
@    @
@700 @void search(trie root,const string& text, const vector<string>& patterns) { //O(M+Z) Custo para buscar em um texto de tamanho M com Z ocorrencias.
@    @
@8B8 @  trie current = root;
@    @
@D41 @  // 1. Percorre o texto um caractere por vez
@1B3 @  for (int i = 0; i < text.length(); ++i) {
@9CC @    int v = text[i] - 'a';
@    @
@D41 @    // 2. Logica de transicao: Se nao houver caminho direto,
@D41 @    //    segue os suffix links (sl) ate encontrar um ou chegar na raiz.
@F6A @    while (current != root && !current->nxt[v]) {
@B87 @      current = current->sl;
@F50 @    }
@723 @    if (current->nxt[v]) {
@523 @      current = current->nxt[v];
@8B3 @    }
@    @
@D41 @    // 3. Verificacao de Padroes: Apos a transicao, verifica se ha
@D41 @    //    algum padrao terminando nesta posicao.
@B03 @    trie temp = current;
@969 @    while (temp != nullptr) {
@D41 @      // Se o no atual representa o fim de um padrao (idx != -1)...
@924 @      if (temp->idx != -1) {
@FED @        int pattern_idx = temp->idx;
@AB1 @        const string& found_pattern = patterns[pattern_idx];
@D41 @        // Calcula a posicao inicial da palavra encontrada
@218 @        int start_pos = i - found_pattern.length() + 1;
@387 @        cout << "  -> Padrao '" << found_pattern << "' encontrado na posicao " << start_pos << endl;
@381 @      }
@D41 @      // ...pula para o proximo padrao na cadeia de sufixos usando o output link (ol).
@80C @      temp = temp->ol;
@261 @    }
@BBD @  }
@08C @}
@    @
@    @
@421 @int cnt_prefix (trie root,const string& prefix){
@3EC @  for(auto c : prefix){
@9AE @    int v = c-'a';
@93B @    if(!root->nxt[v]){
@BB3 @      return 0;
@918 @    }
@D73 @    root= root->nxt[v];
@475 @  }
@197 @  return root->prf_cnt;
@08A @}
@    @
@    @
@    @
@E8D @int main(){
@B95 @  cin.tie(0);
@52E @  ios::sync_with_stdio(0);
@C5F @  int n,q; cin>>n>>q;
@1F1 @  trie root = new node();
@    @
@    @
@BB3 @  return 0;
@9F1 @}
