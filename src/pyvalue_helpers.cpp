#include "pyvalue_helpers.hpp"
#include <iostream>
#include <sstream>
#include <stdio.h>

namespace py {
namespace value_helper {
/*
    visitor_is_truthy
*/
bool visitor_is_truthy::operator()(double d) const {
    return d != (double)0;
}

bool visitor_is_truthy::operator()(int64_t d) const {
    return d != (int64_t)0;
}

bool visitor_is_truthy::operator()(const ValueString& s) const {
    return s->size() != 0;
}

bool visitor_is_truthy::operator()(const value::NoneType) const {
    return false;
}


/*
    visitor_debug_repr
*/
struct visitor_debug_repr {
    std::ostream& stream;
    visitor_debug_repr(std::ostream& stream) : stream(stream) { };

    void operator()(bool v) {
        stream << v ? "true" : "false";
    }

    void operator()(double d) {
        stream << d;
    }

    void operator()(int64_t d) {
        stream << d;
    }

    void operator()(ValueString d) {
        stream << *d;
    }

    void operator()(value::NoneType) {
        stream << "None";
    }

    void operator()(ValuePyFunction func) {
        if (func != nullptr) {
            stream << *(func->name);
        } else 
            stream << "anonymous function";
    }

    void operator()(ValuePyClass) {
        stream << "Class";
    }

    void operator()(ValuePyObject) {
        stream << "Object";
    }

    void operator()(ValueList list) {
        stream << "[";
        for (auto& value : list->values) {
            std::visit(value_helper::visitor_debug_repr(stream), value);
            stream << ", ";
        }
        stream << "]";
    }

    template<typename T> 
    void operator()(T) const {
        // TODO: use typetraits to generate this.
        throw pyerror("unimplemented repr for type");
    }
};

}

std::ostream& operator << (std::ostream& stream, const Value value) {
    std::visit(value_helper::visitor_debug_repr(stream), value);
    return stream;
}

}
