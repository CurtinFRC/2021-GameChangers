#pragma once

struct wfd_paths {
  /**
  * Create a spline using waypoints and control points
  */
  wayfinder::Path::sSpline spline1{
    {{0,0}, {0,5}}, // Waypoints

    {-4,0}, // Start control point
    {10,0} // End Control point
  };

  /**
  * Path to use with follower
  */
  wayfinder::Path::sPath path;

};