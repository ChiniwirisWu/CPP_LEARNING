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
    return values[suit];
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


int main()
{
    Deck deck {};
    while(true){
      std::cout << deck.dealCard() << "\n"; 
    }
    return 0;
}
