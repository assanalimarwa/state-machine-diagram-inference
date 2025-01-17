#include <gtest/gtest.h>
struct Event{};
enum class State
{
  DPI,
  IOT,
  IoT,
  DNS,
  MIM,
  TLD,
  WAP,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DPI)
{
  // CHeck path ['DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, IOT)
{
  // CHeck path ['DPI', 'IOT', 'DNS', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, TLD)
{
  // CHeck path ['DPI', 'IOT', 'TLD', 'DNS', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, DNS)
{
  // CHeck path ['DPI', 'IOT', 'DNS', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, IoT)
{
  // CHeck path ['DPI', 'IOT', 'IoT', 'DNS', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IoT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, MIM)
{
  // CHeck path ['DPI', 'IOT', 'TLD', 'MIM', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::TLD);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MIM);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

TEST(App, WAP)
{
  // CHeck path ['DPI', 'IOT', 'IoT', 'WAP', 'DNS', 'DPI']
  Event event;
  auto state = State::DPI;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IOT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::IoT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::WAP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
}

