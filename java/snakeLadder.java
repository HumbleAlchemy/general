package snakeLadder;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;
class Move {
 
 public int end ;
 public int weight;
 
 public Move(int end, int weight) {
  super();
  this.end = end;
  this.weight = weight;
 }
 
 public String toString() {
  return " -> [ " + end + ", " + weight + " ] ";
 }
 
}
class QueueElement implements Comparable<QueueElement> {
 public int squareIndex;
 public int distanceFromSource;

 public QueueElement(int squareIndex, int distanceFromSource ) {
  super();
  this.squareIndex = squareIndex;
  this.distanceFromSource = distanceFromSource;
 
 }
 @Override
 public int compareTo(QueueElement q) { 
  return this.distanceFromSource - q.distanceFromSource;
 }
 @Override
 public String toString() {
  return "QueueElement [distanceFromSource=" + distanceFromSource
    + ", " + squareIndex + "]";
 }
 
 
}
public class Solution {
 
 public static final int INFINITY = Integer.MAX_VALUE - 300;
 
 static Scanner scan = new Scanner(System.in);
 static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
 public static void main(String[] args) throws NumberFormatException, IOException {
  // no of test case
  int T = Integer.parseInt(in.readLine());
  
  // snakes and ladders
  String snakeLadder = null;
  
  
  String snakeLadderSplit[] = null;
  int snakes = 0;
  int ladders = 0;
  String ladderSE = null, snakeSE = null;
  String[] ladderSEList;
  String[] snakeSEList;
  
  int[] ladderEndList = null;
  int[] snakeEndList = null;
  int start , end ;
  String[] startEnd;
  ArrayList<ArrayList<Move>> board = null;
  for (int i = 0; i < T; i++) {
   snakeLadder = in.readLine();
   ladderSE = in.readLine();
   snakeSE = in.readLine();
   
   snakeLadderSplit = snakeLadder.split(",");
   ladders = Integer.parseInt(snakeLadderSplit[0]);
   snakes = Integer.parseInt(snakeLadderSplit[1]);
   
   
   // take start and end of ladders
   ladderEndList = new int[101];
   
   ladderSEList = ladderSE.split(" ");
   for(String SE : ladderSEList) {
    startEnd = SE.split(",");
    start = Integer.parseInt(startEnd[0]);
    end = Integer.parseInt(startEnd[1]);
    ladderEndList[start] = end;
   }
   // take start and end of snakes
   snakeEndList = new int[100];
   
   snakeSEList = snakeSE.split(" ");
   for(String SE : snakeSEList) {
    startEnd = SE.split(",");
    start = Integer.parseInt(startEnd[0]);
    end = Integer.parseInt(startEnd[1]);
    snakeEndList[start] = end;
   }
   // generate board
   board = genBoard(ladderEndList, snakeEndList);
   int distance[] = new int[101];
   int previous[] = new int[101];
   findShortestPath(board,distance,previous);
   
   for (int j = 0; j < previous.length; j++) {
    System.out.print(" -> " + previous[j]);
   }
   System.out.println();
  }
 }
 
 private static ArrayList<ArrayList<Move>> genBoard(int[] ladderEndList , int[] snakeEndList) {
  ArrayList<ArrayList<Move>> tempBoard = new ArrayList<ArrayList<Move>>();
  ArrayList<Move> temp = new ArrayList<Move>();
  temp.add(new Move(0,0));
  
  // for 1 to 99; 1 -> 2 , 2 -> 3 .... and each has weight one
  for (int i = 1; i < 100; i++) {
   temp = new ArrayList<Move>();
   temp.add(new Move(i+1,1));
   if(ladderEndList[i] != 0) {
    temp.add(new Move(ladderEndList[i],0));   
   } else if(snakeEndList[i] != 0) {
    temp.add(new Move(snakeEndList[i],INFINITY));    
   }
   tempBoard.add(temp);
  }
  
  temp = new ArrayList<Move>();
  temp.add(new Move(-1,-1));
  tempBoard.add(temp);
  // for 100 ; 100 does not point to anything therefore -1,-1
  
  //print
  int square = 0;
  for (ArrayList<Move> moves : tempBoard) {
   System.out.print(++square + ": ");
   for(Move move : moves ) {
    System.out.print(" " + move.toString());
   }
   System.out.println();
  }
  return tempBoard;
 }
 
 private static void findShortestPath(ArrayList<ArrayList<Move>> graph,int[] distance, int[] previous) {
  // initialize previous and distance 
  
  int alt = 0;
  ArrayList<QueueElement> queue = new ArrayList<QueueElement>();
  ArrayList<Move> neighbours = null;
  distance[1] = 0; // source -> source
  queue.add(new QueueElement(1, 0 ));
  for (int i = 2; i < 100; i++) {
   distance[i] = INFINITY;
   previous[i] = -1;
   queue.add(new QueueElement(i, INFINITY ));
  }
  
  while(!queue.isEmpty()) {
   int minIndex = findMinIndex(queue);
   QueueElement qe = queue.remove(minIndex);
   // find neighbours of u
   System.out.println("picking " + qe.squareIndex);
//   if(qe.squareIndex == 100)
//    break;
   neighbours = findNeighbours(qe.squareIndex, graph);
   for (Move move : neighbours) {
    System.out.println(move.end + " neighbour of " + qe.squareIndex + " at dist " + move.weight);
    alt = distance[qe.squareIndex] + move.weight;
    System.out.println( distance[move.end] + " : " + distance[qe.squareIndex] + " + " + move.weight + " = " + alt);
    
    for(int i = 0 ; i < distance.length; i++) {
     System.out.print(" " + distance[i]);
    }
    System.out.println();
    if(alt < distance[move.end]) {
     distance[move.end] = alt;
     previous[move.end] = qe.squareIndex;
     int realIndex = findElementIndex(queue, move.end);
     QueueElement q = queue.remove(realIndex);
     q.distanceFromSource = alt;
     queue.add(q); 
    }
   }
   
  }
 }
 
 private static int findMinIndex(ArrayList<QueueElement> queue) {
  int min = queue.get(0).distanceFromSource;
  int minIndex = 0;
  for (int i = 0; i < queue.size(); i++) {
   if(queue.get(i).distanceFromSource < min) {
    minIndex= i;
    min = queue.get(i).distanceFromSource;
   }
  }
  return minIndex;
 }
 
 private static int findElementIndex(ArrayList<QueueElement> queue,int sqaureIndex) {
  for (int i = 0; i < queue.size(); i++) {
   if(queue.get(i).squareIndex == sqaureIndex) {
    return i;
   }
  }
  return -1;
 }
 private static ArrayList<Move> findNeighbours(int index, ArrayList<ArrayList<Move>> graph ) {
  ArrayList<Move> neighboursInGraph = graph.get(index-1);
  System.out.println("neighbour of " + index);
  
  for (Move move : neighboursInGraph) {
   System.out.print(move.toString() + " ");
  }
  System.out.println();
  return neighboursInGraph;
 }
}
