import java.lang.*;
import java.util.*;
import java.io.*;

public class raidTeams {
	public static void main(String[] args) {
		BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));

		ArrayList<Player> listOfPlayers = new ArrayList<Player>();
		String line;
		String[] values = new String[4];

		int numberOfPlayers = 0;

		try {
			numberOfPlayers = Integer.parseInt(scan.readLine());

			for(int i = 0; i < numberOfPlayers; i++) {
				line = scan.readLine();
				values = line.split(" ");
				listOfPlayers.add(new Player(values[0], Integer.parseInt(values[1]), Integer.parseInt(values[2]), Integer.parseInt(values[3])));
			}

			scan.close();
		}catch(Exception e) {
			e.printStackTrace();
		}

		/*for(Player p : listOfPlayers)
			System.out.println(p.toString());*/

		ArrayList<Team> parties = new ArrayList<Team>();
		int numberOfParties = numberOfPlayers/3;
		Player bestPlayer;

		for(int j = 0; j < numberOfParties; j++) {
			Team team = new Team();

			for(int teamSlot = 1; teamSlot <= 3; teamSlot++) {
				bestPlayer = listOfPlayers.get(0);
				int index = 0;

				switch (teamSlot) {
					case 1:
						for(int i = 1; i < listOfPlayers.size(); i++) {
							if(listOfPlayers.get(i).getSkillLevel1() == bestPlayer.getSkillLevel1() && listOfPlayers.get(i).getPLayerName().compareTo(bestPlayer.getPLayerName()) < 0) {
								bestPlayer = listOfPlayers.get(i);
								index = i;
								continue;
							}

							if(listOfPlayers.get(i).getSkillLevel1() > bestPlayer.getSkillLevel1()) {
								bestPlayer = listOfPlayers.get(i);
								index = i;
								continue;
							}
						}

						team.setPlayer1(bestPlayer);
						listOfPlayers.remove(index);

						break;
					case 2:
						for(int i = 1; i < listOfPlayers.size(); i++) {
							if(listOfPlayers.get(i).getSkillLevel2() == bestPlayer.getSkillLevel2() && listOfPlayers.get(i).getPLayerName().compareTo(bestPlayer.getPLayerName()) < 0) {
								bestPlayer = listOfPlayers.get(i);
								index = i;
								continue;
							}

							if(listOfPlayers.get(i).getSkillLevel2() > bestPlayer.getSkillLevel2()) {
								bestPlayer = listOfPlayers.get(i);
								index = i;
								continue;
							}
						}

						team.setPlayer2(bestPlayer);
						listOfPlayers.remove(index);
						break;
					case 3:
						for(int i = 1; i < listOfPlayers.size(); i++) {
							if(listOfPlayers.get(i).getSkillLevel3() == bestPlayer.getSkillLevel3() && listOfPlayers.get(i).getPLayerName().compareTo(bestPlayer.getPLayerName()) < 0) {
								bestPlayer = listOfPlayers.get(i);
								index = i;
								continue;
							}

							if(listOfPlayers.get(i).getSkillLevel3() > bestPlayer.getSkillLevel3()) {
								bestPlayer = listOfPlayers.get(i);
								index = i;
								continue;
							}
						}

						team.setPlayer3(bestPlayer);
						listOfPlayers.remove(index);
						break;
					default:
						break;
				}
			}

			parties.add(team);
		}

		for(Team t : parties)
			t.printTeamMembers();
	}
}

class Player {
	private int skillLevel1, skillLevel2, skillLevel3;
	private String name;

	public Player(String n, int s1, int s2, int s3) {
		skillLevel3 = s3;
		skillLevel2 = s2;
		skillLevel1 = s1;
		name = n;
	}

	public int getSkillLevel1() {
		return skillLevel1;
	}

	public int getSkillLevel2() {
		return skillLevel2;
	}

	public int getSkillLevel3() {
		return skillLevel3;
	}

	public String getPLayerName() {
		return name;
	}

	public String toString() {
		return name + " " + skillLevel1 + " " + skillLevel2 + " " + skillLevel3;
	}
}

class Team {
	private Player player1, player2, player3;

	public void setPlayer1(Player p) {
		player1 = p;
	}

	public void setPlayer2(Player p) {
		player2 = p;
	}

	public void setPlayer3(Player p) {
		player3 = p;
	}

	public void printTeamMembers() {
		System.out.println(player1.getPLayerName() + " " + player2.getPLayerName() + " " + player3.getPLayerName() + " ");
	}
}