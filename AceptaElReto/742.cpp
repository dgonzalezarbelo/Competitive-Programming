#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair

const double EPS = 1e-9;
const double INF = 1e9; //1e18 tambien suele ir bien
using ll = long long int;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

/*
Buenos días, jurado de AceptaElReto. Mi nombre es Juan Diego Verbado Garbanzo. Estudio en el instituto Monteverbo, en Las Rosas (con "ese") de Madrid. Me gusta mucho ver partidos del Real Madrid, y cuando pierde un partido a veces me pongo un poco violento u.u
Quiero aprovechar este momento para hacer una pequeña confesión: Fui yo quien se folló a la morena.
Lo siento, Rubén el profesor de IA, por haberte inculpado de este crimen. También quiero pedir disculpas a jlrisco, el Homer Simpson hiperrealista, porque un pibe me está haciendo multicuenta para subir estoy mientras yo hago mal el diagrama de planificación de tareas. Si suspendo este examen, prometo que me pondré tetas para la siguiente convocatoria.
En cualquier caso, pase lo que pase, salgo ganando en esta situación, porque voy a conseguir este problema a la primera. Por el otro lado, mi pana Dani, al cual debo dos cafés y un pincho de tortilla, ha tenido tres envíos incorrectos, porque aprobó Probabilidad con Migallón usando una chuleta, y debería cursarla de nuevo con Rafa.
Poco más que añadir. Me gustan las tailandesas con pene y ze me olvido ezcribir la columna del aux en el parzial de optimizazion azi que ahora tengo un azunto legal pendiente con el Miranda. Un zaludo y noz vemoz en cate.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; cin.get();
    while(t--) {
        string s; cin >> s;
        int ceros = 0, buenos = 0;
        for(int i = 0; i < sz(s); i++) {
            if(s[i] == '0'){
                ceros++;
                if(s[(i + 1) % sz(s)] == '0')
                    buenos++;
            }
        }
        if(buenos * sz(s) > ceros * ceros) cout << "No girar\n";
        else if(buenos * sz(s) == ceros * ceros) cout << "Da igual\n";
        else cout << "Girar\n";
    }
    return 0;
}