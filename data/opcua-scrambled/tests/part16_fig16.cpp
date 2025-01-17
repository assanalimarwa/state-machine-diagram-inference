#include <gtest/gtest.h>
struct Event{};
enum class State
{
  EXE,
  DAC,
  CS,
  CDN,
  RAM,
  DOS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, EXE)
{
  // CHeck path ['EXE']
  Event event;
  auto state = State::EXE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
}

TEST(App, CS)
{
  // CHeck path ['EXE', 'CS', 'CDN', 'EXE']
  Event event;
  auto state = State::EXE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CDN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
}

TEST(App, DOS)
{
  // CHeck path ['EXE', 'CS', 'DOS', 'CDN', 'EXE']
  Event event;
  auto state = State::EXE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CDN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
}

TEST(App, CDN)
{
  // CHeck path ['EXE', 'CS', 'CDN', 'EXE']
  Event event;
  auto state = State::EXE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CDN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
}

TEST(App, DAC)
{
  // CHeck path ['EXE', 'CS', 'CDN', 'DAC', 'CDN', 'EXE']
  Event event;
  auto state = State::EXE;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CDN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::CDN);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
}

