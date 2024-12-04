int process(node* n, int maxx, KeyT& ans) {
    if (n == NULL) return 0;
    int l = process(n->left, maxx, ans);
    int r = process(n->right, maxx, ans);
    if (abs(r - l) > maxx || (abs(r - l) == maxx && mLess((n->data).first, ans))) {
        ans = (n->data).first;
        maxx = abs(r - l);
    }
    // std::cout << "sum : " << sum << ", n->data.f : " << (n->data).first << '\n';
    return 1 + std::max(l, r);
}

KeyT getValueOfMostImbalanceNode() {
    // std::cout << "run " << '\n';
    int maxx = -1;
    KeyT ans;
    int temp = process(mRoot, maxx, ans);
    return ans;
}


// int maxx = -1;
// KeyT ans;
// int process(node* n) {
//     if (n == NULL) return 0;
//     int l = process(n->left);
//     int r = process(n->right);
//     if (abs(r - l) > maxx || (abs(r - l) == maxx && mLess((n->data).first, ans))) {
//         ans = (n->data).first;
//         maxx = abs(r - l);
//     }
//     // std::cout << "sum : " << sum << ", n->data.f : " << (n->data).first << '\n';
//     return 1 + std::max(l, r);
// }

// KeyT getValueOfMostImbalanceNode() {
//     // std::cout << "run " << '\n';
//     int temp = process(mRoot);
//     return ans;
// }