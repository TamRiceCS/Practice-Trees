class node {
    public:
        int val = 0;
        node* left = nullptr;
        node* right = nullptr;

        node(int value) {
            val = value;
        }

        node(int value, node* l, node* r) {
            val = value;
            left = l;
            right = r;
        }
};
