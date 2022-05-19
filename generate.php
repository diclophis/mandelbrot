<?php

list($left_x, $lower_y, $right_x, $upper_y) = (explode(',', $_REQUEST['BBOX']));

$tmp = sprintf("/var/tmp/mandelbrot/%s_%s_%s_%s.jpeg", $left_x, $lower_y, $right_x, $upper_y);

if (!file_exists($tmp)) {
  $taskset = "taskset";
  $taskset_select = "-c";
  $taskset_core = abs($left_x) % 4;
  //$zoom = intval((((1.0 / (((abs(doubleval($left_x - $right_x))) * 1.1)))) * 2048.0) / 4);
  $width = doubleval($_REQUEST['WIDTH']);
  $dist = abs(doubleval($left_x - $right_x));
  $zoom = 1024; //intval(2048.0 - (1.0 - (log($dist / $width))));

  $cmd = "/var/www/html/jbardin-fractal";
  $cwd = '/var/tmp/mandelbrot';
  $env = array();
  $descriptorspec = array(
     0 => array("pipe", "r"),  // stdin is a pipe that the child will read from
     1 => array("pipe", "w"),  // stdout is a pipe that the child will write to
     2 => array("pipe", "w") // stderr is a file to write to
  );
  $process = proc_open(array($taskset, $taskset_select, $taskset_core, $cmd, $zoom, $left_x, $lower_y, $right_x, $upper_y, $tmp), $descriptorspec, $pipes, $cwd, $env);
  $return_value = proc_close($process);
}

header('Content-Type: image/jpeg');

readfile($tmp);

?>
