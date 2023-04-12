# Actions
```C++
// override this
Action::perform(Engine& engine)=0;
```
Remember that Actions contain a share_ptr<Actor> called actor

## Results
Result Types: 
-success() 
--//action worked, actor finished with turn
-failure() 
--// failed action, actor gets another turn
-alternative(AnotherAction{}) 
--// action failed, do this instead (ei. door, then move)

# Rest

```C++
// do nothing
class Rest : public Action {
public:
    Result perform(Engine& engine) override;
};
```
cpp file for results and the rest action

# Results: in engine/action.h

```C++
// the result of performing an action
struct Result {
    bool succeeded{false};

    //allow chaining of actions
    std::unique_ptr<Action> next_action{nullptr};
}
```

## Result - Action
If new pos is wall
    return failure();
If new pos is door
    return alternative(OpenDoor{});

## Result - Monster
```C++
for each neighboring tile:
    if tile is walkable AND has no actor:
        return alternative(Move{})
// no empty tile to move to -> rest this turn
return alernative(Rest{})
```

# Position
Vec is class and 2D vector
can add and subtract vectors
