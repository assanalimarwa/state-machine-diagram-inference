#include <gtest/gtest.h>
struct Event{};
enum class State
{
  SLQ,
  SSH,
  IAM,
  PHP,
  SDK,
  WAF _DV,
  RDP,
  MFA,
  SQL,
  CDN,
};
State handle_event(State const state, Event const & evnet);

TEST(App, IAM)
{
  // CHeck path ['IAM']
  Event event;
  auto state = State::IAM;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IAM);
}

