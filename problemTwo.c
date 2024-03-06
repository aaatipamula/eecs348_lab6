#include <complex.h>
#include <stdio.h>

void solve(int score) {
  for (int td_2p = 0; td_2p*8 <= score; td_2p++) {
  for (int td_fg = 0; td_2p*8 + td_fg*7 <= score; td_fg++) {
  for (int td = 0; td_2p*8 + td_fg*7 + td*6 <= score; td++) {
  for (int fg = 0; td_2p*8 + td_fg*7 + td*6 + fg*3 <= score; fg++) {
    int saftey = score - (td_2p*8 + td_fg*7 + td*6 + fg*3);
    if (saftey % 2 == 0) {
      saftey /= 2;
      printf("%d TD + 2, %d TD + FG, %d TD, %d FG, %d Saftey\n", td_2p, td_fg, td, fg, saftey); 
    }
  }}}}}

int user_score;

int main() {

  printf("Enter 0 or 1 to stop\nEnter the NFL score: ");
  scanf("%d", &user_score);

  if (user_score == 1 || user_score == 0) {
    printf("Exiting program...\n");
    return 0;
  }

  printf("Possible combinations of scoring plays:\n");
  solve(user_score);

  return 0;
}
