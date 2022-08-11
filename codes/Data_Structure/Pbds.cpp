template<typename T>
using pbds_tree = tree<T, null_type, less<T>,
      rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order: like array accessing, order_of_key
