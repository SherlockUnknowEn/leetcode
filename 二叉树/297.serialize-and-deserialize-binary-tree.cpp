/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
        {
            return "#";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        serData.clear();
        split(data, serData, ",");
        return de();
    }

    TreeNode* de() {
        if (serData.size() == 0)
        {
            return nullptr;
        }
        
        if (index < serData.size() && serData[index] == "#")
        {
            index++;
            return nullptr;
        }

        // printf("%s ", serData[index].c_str());
        TreeNode* root = new TreeNode(stoi(serData[index]));
        index++;
        root->left = de();
        root->right = de();
        return root;
    }

    void split(const string& s, vector<string>& tokens, const string& delmit = " ") {
        if (s.length() == 0) return;
        string ss(s);
        size_t i = ss.find(delmit);
        while (string::npos != i)
        {
            tokens.push_back(ss.substr(0, i));
            if (i + 1 >= ss.length())
            {
                return;
            }
            ss = ss.substr(i + 1);
            i = ss.find(delmit);
        }
        tokens.push_back(ss);
    }


private:
    int index = 0;
    vector<string> serData;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

