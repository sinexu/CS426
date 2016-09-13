uint64_t graph::add_node(uint64_t node_id){

}
uint64_t graph::add_edge(uint64_t node_a_id, uint64_t node_b_id){

}
uint64_t graph::remove_node(uint64_t node_id){

}
uint64_t graph::remove_edge(uint64_t node_a_id, uint64_t node_b_id){

}
bool graph::get_node(uint64_t node_id){
//    return nodes.enum_keys().contains(node_id);
    return nodes.find(node_id) != nodes.end();
}
pair<bool,bool> graph::get_edge(uint64_t node_a_id, uint64_t node_b_id){
    bool node_a_exist = FALSE;
    bool node_b_exist = FALSE;
    if (nodes.find(node_a_id)!= nodes.end()) {
        node_a_exist = TRUE;
    }
    if (nodes.find(node_b_id) != nodes.end()) {
        node_b_exist = TRUE;
    }
    return pair<node_a_exist, node_b_exist>;
}
unordered_set<node> graph::get_neighbors(uint64_t node_id){
    if (get_node(node_id)) {
        return nodes.at(node_id);
    }
}
uint64_t graph::shortest_path(uint64_t node_a_id, uint64_t node_b_id){

}