#include <iostream>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/state.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>

namespace sc = boost::statechart;

// 定义事件
struct EventToggle : sc::event<EventToggle> {};

// 定义状态
struct Active;
struct Inactive;

// 定义状态机
struct StateMachine : sc::state_machine<StateMachine, Active> {};

// 定义状态 Active
struct Active : sc::simple_state<Active, StateMachine> {
    typedef sc::transition<EventToggle, Inactive> reactions;
    
    Active() { std::cout << "Active State Entered" << std::endl; }
    ~Active() { std::cout << "Leaving Active State" << std::endl; }
};

// 定义状态 Inactive
struct Inactive : sc::simple_state<Inactive, StateMachine> {
    typedef sc::transition<EventToggle, Active> reactions;

    Inactive() { std::cout << "Inactive State Entered" << std::endl; }
    ~Inactive() { std::cout << "Leaving Inactive State" << std::endl; }
};

int main() {
    StateMachine sm;
    sm.initiate();

    // 触发事件，从 Active 转换到 Inactive
    sm.process_event(EventToggle());
    
    // 触发事件，从 Inactive 转换回 Active
    sm.process_event(EventToggle());

    return 0;
}
