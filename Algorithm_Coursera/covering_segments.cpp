#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end, passed;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  bool ifStatementNotRun = true;
  vector<Segment> sortedSegments(segments.size());
  sortedSegments[0] = segments[0];

  for (int i=1; i<segments.size(); i++) {
    for (int j=0; j<segments.size(); j++) {
      if (segments[i].start < sortedSegments[j].start) {
        // std::cout << sortedSegments[j].start << segments[i].start << std::endl;
        ifStatementNotRun = false;
        // insert segments[i] before sortedSegments[j]
        Segment temp = sortedSegments[j];
        Segment temp2 = sortedSegments[j];
        for (int k=j+1; k<segments.size(); k++) {  
          temp = temp2;
          temp2 = sortedSegments[k];       
          sortedSegments[k] = temp;
        }
        sortedSegments[j] = segments[i];
        // std::cout << sortedSegments[j].start << std::endl;
        break;
      }
    }
    if (ifStatementNotRun) {
      sortedSegments[i] = segments[i];
    } else {
      ifStatementNotRun = true;
    }
  }







  bool lessThan2SegmentsLeft = false;
  int nthSegment = 0;
  std::vector<Segment> sections;
  while (true) {
    if (nthSegment > sortedSegments.size()-1) {
      break;
    }
    if (nthSegment >= sortedSegments.size()-2) {
      lessThan2SegmentsLeft = true;
    }

    long long difference;



    if (nthSegment == sortedSegments.size()-1) {



      Segment overlap;
      overlap.start = sortedSegments[nthSegment].start;
      overlap.end = sortedSegments[nthSegment].end;

      Segment prevOverlap = sections[sections.size()-1];

      if (prevOverlap.end < overlap.start) {
        sections.push_back(overlap);
        break;
      }
      if (prevOverlap.end < overlap.end) {
        overlap.end = prevOverlap.end;
      }
      if (prevOverlap.start > overlap.start) {
        overlap.start = prevOverlap.start;
      }

      if (prevOverlap.start <= overlap.start && prevOverlap.end > overlap.end) {
        sections.push_back(overlap);
        break;
      }

      sections.pop_back();
      sections.push_back(overlap);








      if (sortedSegments[nthSegment].end < sortedSegments[nthSegment+1].end) {
        overlap.end = sortedSegments[nthSegment].end;
      }
      else {
        overlap.end = sortedSegments[nthSegment+1].end;      
      }

      
      break;
    }
    else {
      difference = sortedSegments[nthSegment].end - sortedSegments[nthSegment+1].start;
    }
     

  

    Segment overlap;
    bool proceed;
    if (difference > 0) {
      // we have an overlap     
      overlap.start = sortedSegments[nthSegment+1].start;

      if (sortedSegments[nthSegment].end < sortedSegments[nthSegment+1].end) {
        overlap.end = sortedSegments[nthSegment].end;
      }
      else {
        overlap.end = sortedSegments[nthSegment+1].end;      
      }

      if (sections.size() == 0) {
        sections.push_back(overlap);

        if (nthSegment+2 == sortedSegments.size()-1) {
          // last segment after nthSegment += 2
          nthSegment++;
          continue;
        }

        if (lessThan2SegmentsLeft) {
          nthSegment++;
          continue;
        }

        if ((sortedSegments[nthSegment+2].start > sortedSegments[nthSegment+1].end)) {
          nthSegment++;
        }
        else {
          nthSegment += 2;        
        }
        continue;
      }      
      proceed = true;
    } 





    else if (difference == 0) {
      // Segment overlap;
      overlap.start = sortedSegments[nthSegment+1].start;
      overlap.end = overlap.start;

      // std::cout << overlap.start << ' ' << overlap.end << std::endl;


      if (sections.size() == 0) {
        sections.push_back(overlap);


        if (nthSegment+2 == sortedSegments.size()-1) {
          // last segment after nthSegment += 2
          nthSegment++;
          continue;
        }


        if (lessThan2SegmentsLeft) {
          nthSegment++;
          continue;
        }



        if ((sortedSegments[nthSegment+2].start > sortedSegments[nthSegment+1].end)) {
          nthSegment++;
        }
        else {
          nthSegment += 2;        
        }
        continue;
      }






      // if (lessThan2SegmentsLeft) {
      //   sections.push_back(overlap);
      //   break;
      // }

      // if ((sortedSegments[nthSegment+2].start) == sortedSegments[nthSegment+1].end) {
      //   overlap.start = sortedSegments[nthSegment+1].end;
      //   overlap.end = overlap.start;
      //   sections.push_back(overlap);


      //   // std::cout << overlap.start << ' ' << overlap.end << std::endl;
      // }

      // if (nthSegment+2 == sortedSegments.size()-1) {
      //   // last segment after nthSegment += 2
      //   nthSegment++;
      //   continue;
      // }


        
      // std::cout << overlap.end << std::endl;
       




      proceed = true;
    }
    else {
      proceed = false;
      overlap.start = sortedSegments[nthSegment+1].start;
      overlap.end = sortedSegments[nthSegment+1].end;
      sections.push_back(overlap);

      // std::cout << overlap.start << ' ' << overlap.end << std::endl;

      nthSegment++;
      continue;
    }

    // std::cout << overlap.end << std::endl;



    if (proceed) {
      Segment prevOverlap = sections[sections.size()-1];



      // std::cout << prevOverlap.end << std::endl;
      // std::cout << overlap.start << std::endl;
      if (prevOverlap.end < overlap.start) {

        if ((sortedSegments[nthSegment].start <= prevOverlap.end && sortedSegments[nthSegment].end >= prevOverlap.start)) {
        // segment covered by prevOverlap
        // std::cout << "YES" << std::endl;
        if (sortedSegments[nthSegment+1].start > prevOverlap.end) {
          if (sortedSegments[nthSegment+2].start <= sortedSegments[nthSegment+1].end) {
            // std::cout << "YES" << std::endl;
            nthSegment++;
            continue;
          }
          
        }
        // sections.pop_back();
        // sections.push_back(overlap);
        // nthSegment++;
        // continue;
      }

        // std::cout << overlap.start << std::endl;
        sections.push_back(overlap);
        if ((sortedSegments[nthSegment+2].start > sortedSegments[nthSegment+1].end) && !lessThan2SegmentsLeft) {
          nthSegment += 1;
        }
        else if (lessThan2SegmentsLeft) {
          nthSegment++;
          continue;
        }
        else if (nthSegment+2 == sortedSegments.size()-1) {
          // last segment after nthSegment += 2
          nthSegment++;
          continue;
        }
        else if ((sortedSegments[nthSegment+3].start > (sortedSegments[nthSegment+2].end))) {
          nthSegment++;
          continue;
        }
        else {
          nthSegment += 2;        
        }

        
        continue;
      }
      if (prevOverlap.end < overlap.end) {
        overlap.end = prevOverlap.end;
      }


      // if ((sortedSegments[nthSegment].start <= prevOverlap.end && sortedSegments[nthSegment].end >= prevOverlap.start)) {
      //   // segment covered by prevOverlap
      //   std::cout << "YES" << std::endl;
      //   if (sortedSegments[nthSegment+1].start > prevOverlap.end) {
      //     std::cout << "YES" << std::endl;
      //     nthSegment++;
      //     continue;
      //   }
      //   // sections.pop_back();
      //   // sections.push_back(overlap);
      //   // nthSegment++;
      //   // continue;
      // }

      sections.pop_back();
      sections.push_back(overlap);

      if (nthSegment+2 == sortedSegments.size()-1) {
      // last segment after nthSegment += 2
      nthSegment++;
      continue;
    }





    if (lessThan2SegmentsLeft) {
      nthSegment++;
      continue;
    }

    if ((sortedSegments[nthSegment+3].start > (sortedSegments[nthSegment+2].end))) {
      // std::cout << "YES" << std::endl;
      nthSegment++;
      continue;
    }

    



    if ((sortedSegments[nthSegment+2].start > sortedSegments[nthSegment+1].end)) {
      nthSegment++;
    }
    // else if (lessThan2SegmentsLeft) {
    //   nthSegment++;
    // }
    else {
      nthSegment += 2;        
    }
    }


    // if (nthSegment+2 == sortedSegments.size()-1) {
    //   // last segment after nthSegment += 2
    //   nthSegment++;
    //   continue;
    // }


    // if (lessThan2SegmentsLeft) {
    //   nthSegment++;
    //   continue;
    // }

    // if ((sortedSegments[nthSegment+3].start > (sortedSegments[nthSegment+2].end))) {
    //   std::cout << "YES" << std::endl;
    //   nthSegment++;
    //   continue;
    // }



    // if ((sortedSegments[nthSegment+2].start > sortedSegments[nthSegment+1].end)) {
    //   nthSegment++;
    // }
    // // else if (lessThan2SegmentsLeft) {
    // //   nthSegment++;
    // // }
    // else {
    //   nthSegment += 2;        
    // }
  }

  for (int i=0; i<sections.size(); i++) {
    points.push_back(sections[i].end);
  }





  

  for (int i=0; i<sortedSegments.size(); i++) {
    sortedSegments[i].passed = 0;
  }

  for (int i=0; i<points.size(); i++) {
    for (int j=0; j<sortedSegments.size(); j++) {
      if (sortedSegments[j].start <= points[i] && sortedSegments[j].end >= points[i]) {
        // std::cout << "YES" << std::endl;
        // std::cout << sortedSegments[j].start << ' ' << sortedSegments[j].end << std::endl;
        sortedSegments[j].passed = 1;
      }
    }
  }

  for (int i=0; i<sortedSegments.size(); i++) {
    // std::cout << sortedSegments[i].start << ' ' << sortedSegments[i].end << ' ' << sortedSegments[i].passed << std::endl;
    if (sortedSegments[i].passed != 1) {
      points.push_back(sortedSegments[i].end);
    }
  }




  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
