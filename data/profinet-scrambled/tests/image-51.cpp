#include <gtest/gtest.h>
struct Event{};
enum class State
{
  DPI,
  JDK,
  PPT,
  XSS,
  BIOS,
  MFA,
  DOS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DOS)
{
  // CHeck path ['DOS']
  Event event;
  auto state = State::DOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
}

TEST(App, PPT)
{
  // CHeck path ['DOS', 'PPT', 'DOS']
  Event event;
  auto state = State::DOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
}

TEST(App, DPI)
{
  // CHeck path ['DOS', 'PPT', 'DPI', 'DOS']
  Event event;
  auto state = State::DOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
}

TEST(App, BIOS)
{
  // CHeck path ['DOS', 'PPT', 'DPI', 'BIOS', 'DOS']
  Event event;
  auto state = State::DOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
}

TEST(App, JDK)
{
  // CHeck path ['DOS', 'PPT', 'DPI', 'BIOS', 'JDK', 'DOS']
  Event event;
  auto state = State::DOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
}

TEST(App, XSS)
{
  // CHeck path ['DOS', 'PPT', 'DPI', 'BIOS', 'JDK', 'XSS', 'DOS']
  Event event;
  auto state = State::DOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
}

TEST(App, MFA)
{
  // CHeck path ['DOS', 'PPT', 'DPI', 'BIOS', 'JDK', 'XSS', 'MFA', 'DOS']
  Event event;
  auto state = State::DOS;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PPT);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DPI);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::JDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MFA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
}

