<?php

list($left_x, $lower_y, $right_x, $upper_y) = (explode(',', $_REQUEST['BBOX']));

$tmp = sprintf("/var/tmp/mandelbrot/%s_%s_%s_%s.jpeg", $left_x, $lower_y, $right_x, $upper_y);

if (!file_exists($tmp)) {
  $cmd = "/var/www/html/jbardin-fractal";
  $cwd = '/var/tmp/mandelbrot';
  $env = array();
  $descriptorspec = array(
     0 => array("pipe", "r"),  // stdin is a pipe that the child will read from
     1 => array("pipe", "w"),  // stdout is a pipe that the child will write to
     2 => array("pipe", "w") // stderr is a file to write to
  );
  $process = proc_open(array($cmd, $left_x, $lower_y, $right_x, $upper_y, $tmp), $descriptorspec, $pipes, $cwd, $env);
  $return_value = proc_close($process);
}

header('Content-Type: image/jpeg');

readfile($tmp);

?>
