#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

struct node { // pode adicionar um contador de prefixos
  node* p = nullptr;
  node* nxt[26] = {};
  node* sl = nullptr; // suffix link
  node* ol = nullptr; // output link
  int c;
  int idx = -1; // -1 indica que não eh fim de palavra.
  int prf_cnt =0;                
};


typedef node* trie;
//trie root = new node();

void add(trie root ,const string& s, int pattern_idx) { // O(S)
  trie t = root;
  t->prf_cnt++;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    int v = c - 'a';
    if (!t->nxt[v]) {
      trie son = new node();
      son->c = v;
      son->p = t;
      t->nxt[v] = son;
    }
    t = t->nxt[v];
    t->prf_cnt++;
  }
    
  t->idx = pattern_idx;
} 
void buildLinks(trie root) { // O(L) L-> numero de nós
 
  root->sl = root; 
  
  queue<trie> q;
  for(int i = 0; i < 26; i++) {
    if(root->nxt[i]) {
      q.push(root->nxt[i]);
      root->nxt[i]->sl = root; // Filhos da raiz tem sl para a raiz
    }
  }

  while (!q.empty()) {
    trie t = q.front();
    q.pop();

    for (int c = 0; c < 26; c++) {
      if (t->nxt[c]) {
        trie son = t->nxt[c];
        trie w = t->sl;
        while (w != root && !w->nxt[c]) {
          w = w->sl;
        }
        if (w->nxt[c]) {
          son->sl = w->nxt[c];
        } else {
          son->sl = root;
        }

        //LOGICA DO OUTPUT LINK
        // Verifica se o no do suffix link eh o fim de uma palavra.
        // Se for (idx != -1), o output link aponta para ele.
        // Senao, herda o output link dele.
        if (son->sl->idx != -1) {
          son->ol = son->sl;
        } else {
          son->ol = son->sl->ol;
        }
        
        q.push(son);
      }
    }
  }
}

void search(trie root,const string& text, const vector<string>& patterns) { //O(M+Z) Custo para buscar em um texto de tamanho M com Z ocorrencias.

  trie current = root;

  // 1. Percorre o texto um caractere por vez
  for (int i = 0; i < text.length(); ++i) {
    int v = text[i] - 'a';

    // 2. Logica de transicao: Se não houver caminho direto,
    //    segue os suffix links (sl) até encontrar um ou chegar na raiz.
    while (current != root && !current->nxt[v]) {
      current = current->sl;
    }
    if (current->nxt[v]) {
      current = current->nxt[v];
    }

    // 3. Verificação de Padroes: Após a transicao, verifica se ha
    //    algum padrão terminando nesta posicao.
    trie temp = current;
    while (temp != nullptr) {
      // Se o no atual representa o fim de um padrão (idx != -1)...
      if (temp->idx != -1) {
        int pattern_idx = temp->idx;
        const string& found_pattern = patterns[pattern_idx];
        // Calcula a posição inicial da palavra encontrada
        int start_pos = i - found_pattern.length() + 1;
        cout << "  -> Padrão '" << found_pattern << "' encontrado na posição " << start_pos << endl;
      }
      // ...pula para o proximo padrao na cadeia de sufixos usando o output link (ol).
      temp = temp->ol;
    }
  }
}


int cnt_prefix (trie root,const string& prefix){
  for(auto c : prefix){
    int v = c-'a';
    if(!root->nxt[v]){
      return 0;
    }
    root= root->nxt[v];
  }
  return root->prf_cnt;
}



int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,q; cin>>n>>q;
  trie root = new node();
  
  
  return 0;
}
