#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    vector<list<string> > table;

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        list<string> *chain = &table[hash_func(query.s)];
        list<string>::iterator it;
        if (query.type == "check") {
            chain = &table[query.ind];
            for (it = chain->begin(); it != chain->end(); ++it) {
                cout << *it << " ";
            }
            std::cout << "\n";
        } 
        else {
            if (query.type == "find") {
                for (it = chain->begin(); it != chain->end(); ++it) {
                    if (*it == query.s) {
                        writeSearchResult(true);
                        return;
                    }
                }
                writeSearchResult(false);
            }
            else if (query.type == "add") {     
                for (it = chain->begin(); it != chain->end(); ++it) {
                    if (*it == query.s) {
                        return;
                    }
                }
                chain->push_front(query.s);
            } 
            else if (query.type == "del") {
                for (it = chain->begin(); it != chain->end(); ++it) {
                    if (*it == query.s) {
                        chain->erase(it);
                        return;
                    }
                }
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        table.resize(bucket_count);
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
