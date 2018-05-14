#ifndef OBJECT_PROPERTY_TREE_CONSTRUCT_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_CONSTRUCT_HH_INCLUDED

namespace opt {

/*

struct tree {

    < T1 , T2 , T3 ... > 
    op[name] -> tree_node[]
}

*/

template <typename... Elements>
auto construct(node<Elements...> const& tree) { return {};
}

}

#endif
