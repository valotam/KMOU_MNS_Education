#include <array>
#include <iostream>
#include <random>

enum class CardSuit {
  CLUB,
  DIAMOND,
  HEART,
  SPADE,
  MAX_SUITS,
};

enum class CardRank {
  R_2,
  R_3,
  R_4,
  R_5,
  R_6,
  R_7,
  R_8,
  R_9,
  R_10,
  R_JACK,
  R_QUEEN,
  R_KING,
  R_ACE,
  MAX_RANKS,
};

enum class BlackjackProps {
  DEALER_LIMIT = 17,
  BLACKJACK = 21,
  NUM_CARDS = static_cast<int>(CardSuit::MAX_SUITS) *
              static_cast<int>(CardRank::MAX_RANKS),
};

struct Card {
  CardRank rank;
  CardSuit suit;
};

void PrintCard(const Card &card) {
  switch (card.rank) {
    case CardRank::R_2:     std::cout << '2'; break;
    case CardRank::R_3:     std::cout << '3'; break;
    case CardRank::R_4:     std::cout << '4'; break;
    case CardRank::R_5:     std::cout << '5'; break;
    case CardRank::R_6:     std::cout << '6'; break;
    case CardRank::R_7:     std::cout << '7'; break;
    case CardRank::R_8:     std::cout << '8'; break;
    case CardRank::R_9:     std::cout << '9'; break;
    case CardRank::R_10:    std::cout << 'T'; break;
    case CardRank::R_JACK:  std::cout << 'J'; break;
    case CardRank::R_QUEEN: std::cout << 'Q'; break;
    case CardRank::R_KING:  std::cout << 'K'; break;
    case CardRank::R_ACE:   std::cout << 'A'; break;
  }

  switch (card.suit) {
    case CardSuit::CLUB:    std::cout << 'C'; break;
    case CardSuit::DIAMOND: std::cout << 'D'; break;
    case CardSuit::HEART:   std::cout << 'H'; break;
    case CardSuit::SPADE:   std::cout << 'S'; break;
  }
}

void PrintDeck(
    const std::array<Card, static_cast<int>(BlackjackProps::NUM_CARDS)> &deck) {
  for (const auto &card : deck) {
    PrintCard(card);
    std::cout << ' ';
  }

  std::cout << '\n';
}

void SwapCard(Card &a, Card &b) {
  Card temp = a;
  a = b;
  b = temp;
}

int GetRandomNumber(const int min, const int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(min, max);
  return dis(gen);
}

void ShuffleDeck(
    std::array<Card, static_cast<int>(BlackjackProps::NUM_CARDS)> &deck) {
  // Step through each card in the deck
  for (
      int deck_card_idx = 0;
      deck_card_idx < static_cast<int>(BlackjackProps::NUM_CARDS);
      ++deck_card_idx) {
    // Pick a random card, any card
    int swap_idx =
        GetRandomNumber(0, static_cast<int>(BlackjackProps::NUM_CARDS) - 1);
    // Swap it with the current card
    SwapCard(deck[deck_card_idx], deck[swap_idx]);
  }
}

int GetCardValue(const Card &card) {
  switch (card.rank) {
    case CardRank::R_2:     return 2;
    case CardRank::R_3:     return 3;
    case CardRank::R_4:     return 4;
    case CardRank::R_5:     return 5;
    case CardRank::R_6:     return 6;
    case CardRank::R_7:     return 7;
    case CardRank::R_8:     return 8;
    case CardRank::R_9:     return 9;
    case CardRank::R_10:    return 10;
    case CardRank::R_JACK:  return 10;
    case CardRank::R_QUEEN: return 10;
    case CardRank::R_KING:  return 10;
    case CardRank::R_ACE:   return 11;
  }

  return 0;
}

char GetPlayerChoice() {
  std::cout << "(h) to hit, or (s) to stand: ";
  char choice;
  do {
    std::cin >> choice;
  } while (choice != 'h' && choice != 's');

  return choice;
}

bool PlayBlackjack(
    const std::array<Card, static_cast<int>(BlackjackProps::NUM_CARDS)> &deck){
  // Set up the initial game state
  const Card *card_ptr = &deck[0];

  int player_total = 0;
  int dealer_total = 0;

  // Deal the dealer one card
  dealer_total += GetCardValue(*card_ptr++);
  std::cout << "The dealer is showing: " << dealer_total << '\n';

  // Deal the player two cards
  player_total += GetCardValue(*card_ptr++);
  player_total += GetCardValue(*card_ptr++);

  // Player goes first
  while (1) {
    std::cout << "You have: " << player_total << '\n';

    // See if the player busted
    if (player_total > static_cast<int>(BlackjackProps::BLACKJACK))
      return false;

    char choice = GetPlayerChoice();
    if (choice == 's') break;

    player_total += GetCardValue(*card_ptr++);
  }

  // If player hasn't busted, dealer goes until he has at least 17 points
  while (dealer_total < static_cast<int>(BlackjackProps::DEALER_LIMIT)) {
    dealer_total += GetCardValue(*card_ptr++);
    std::cout << "The dealer now has: " << dealer_total << '\n';
  }

  // If dealer busted, player wins
  if (dealer_total > static_cast<int>(BlackjackProps::BLACKJACK)) return true;

  return (player_total > dealer_total);
}

int main() {
  std::array<Card, static_cast<int>(BlackjackProps::NUM_CARDS)> deck;

  // We could initialize each card individually, but that would be a pain.
  // Let's use a loop.
  int card = 0;
  for (int suit = 0; suit < static_cast<int>(CardSuit::MAX_SUITS); ++suit)
    for (int rank = 0; rank < static_cast<int>(CardRank::MAX_RANKS); ++rank) {
      deck[card].suit = static_cast<CardSuit>(suit);
      deck[card].rank = static_cast<CardRank>(rank);
      ++card;
    }

  ShuffleDeck(deck);

  if (PlayBlackjack(deck))
    std::cout << "You win!\n";
  else
    std::cout << "You lose!\n";

  return 0;
}
