#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
tcT> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
tcT> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
tcTU> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
tcTU> using ordered_multimap = tree<T, U, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
