#include <iostream>
#include <string_view> 
#include <vector>
#include <array>
#include <cassert>
#include <algorithm>
#include "random.h"

struct Card{

  enum Rank{
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    max_rank,
  };

  enum Suit{
    suit_diamond,
    suit_club,
    suit_heart,
    suit_spade,
    max_suit,
  };

  static constexpr std::array all_ranks {rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king};
  static constexpr std::array all_suits {suit_diamond, suit_club, suit_heart, suit_spade};

  Rank rank;
  Suit suit;

  friend std::ostream& operator <<(std::ostream& out, const Card& card){
    std::array<char, Card::max_rank> ranks {'A', '2', '3', '4','5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    std::array<char, Card::max_suit> suits {'D','C', 'H', 'S'};
    
    out << ranks[card.rank] << suits[card.suit];
    return out;
  }

  int value () const {
    constexpr std::array values {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};
    return values[rank];
  }

};

class Deck{
private:
  static constexpr int max_cards {52};
  std::array<Card, max_cards> m_cards {};
  int m_index {0};
public:
  Deck(){
    int index {0};
    for(const auto rank : Card::all_ranks) {
      for(const auto suit : Card::all_suits){
        m_cards[index] = Card{rank, suit};
        index++;
      }
    }
  };

  void shuffle () {
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_index = 0;
  }

  void printDeck () const {
    for(const auto card : m_cards){
      std::cout << card << " ";
    }
  }

  Card dealCard() {
    assert(m_index < max_cards && "Deck::dealcard ran out of cards");
    return m_cards[m_index++];
  };

};

struct Player {
  int score;
};

namespace Settings{
  constexpr int target {21};
  constexpr int dealerThreshold {17};
};

bool dealerTurn(Player& dealer, Deck& deck){
  while(dealer.score < Settings::dealerThreshold){

    Card card { deck.dealCard() };
    dealer.score += card.value();

    std::cout << "The dealer filps a " << card << ". ";
    std::cout << "They now have: " << dealer.score << '\n';
  }

  if(dealer.score > Settings::target){
    std::cout << "The dealer went burst!\n";
    return false; // player winss.
  } 

  return true;
};

bool playerTurn(Player& player, Deck& deck){
  char option {};
  while(player.score < Settings::target){
    std::cout << "(h) to hit, or (s) to stand: ";
    std::cin >> option;

    if(option == 'h'){
      Card card { deck.dealCard() };
      player.score +=  card.value();

      std::cout << "You have dealt a " << card << ". ";
      std::cout << "They now have: " << player.score << '\n';
      continue;
    }

    if(option == 's'){
      break;
    }
  }

  if(player.score > Settings::target){
    std::cout << "You went burst!\n";
    return false;
  }

  return true;
};

bool playBlackJack () {

  Deck deck {};
  deck.shuffle();

  Player dealer { deck.dealCard().value() };  
  std::cout << "Dealer shows: " << dealer.score << '\n';

  Player player {deck.dealCard().value() + deck.dealCard().value() };
  std::cout << "Player shows: " << player.score << '\n';

  if(!playerTurn(player, deck)){
    return false;
  }

  // dealer turn.
  if(!dealerTurn(dealer, deck)){
    return true; 
  }

  return player.score > dealer.score;
};


int main()
{
  if(playBlackJack()){
    std::cout << "You won!\n"; 
  } else {
    std::cout << "You lost!\n"; 
  }
  return 0;
}
