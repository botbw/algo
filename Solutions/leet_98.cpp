#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#include "leet/TreeNode.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> a;
    bool isValidBST(TreeNode* root) {
        dfs(root);
        bool ok = true;
        for(int i = 1; i < (int)a.size(); i++) {
          if(a[i-1] >= a[i]) {
            ok = false;
            break;
          }
        }
        return ok;
    }

    void dfs(TreeNode* x) {
      if(x->left) dfs(x->left);
      a.push_back(x->val);
      if(x->right) dfs(x->right);
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}