<?php

list($left_x, $lower_y, $right_x, $upper_y) = (explode(',', $_REQUEST['BBOX']));

settype($left_x, "double");
settype($lower_y, "double");
settype($right_x, "double");
settype($upper_y, "double");

//$tmp = sprintf("/tmp/%.99.%.99f.%g.%g.jpeg", $left_x, $lower_y, $right_x, $upper_y);
$tmp = sprintf("/tmp/%.99f_%.99f_%.99f_%.99f.jpeg", $left_x, $lower_y, $right_x, $upper_y);

if (!file_exists($tmp)) {
  $cmd = sprintf("/var/www/html/jbardin-fractal %.99f %.99f %.99f %.99f %s", ($left_x), ($lower_y), ($right_x), ($upper_y), $tmp);
  system($cmd);
}

header('Content-Type: image/jpeg');

readfile($tmp);

?>
