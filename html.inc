<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <title>Twitter OAuth in PHP</title>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    <style type="text/css">
      img {border-width: 0}
      * {font-family:'Lucida Grande', sans-serif;}
    </style>
  </head>
  <body>
    <div>
      <h2>Welcome to a Twitter OAuth PHP example.</h2>

      <p>This site is a basic showcase of Twitters OAuth authentication method. If you are having issues try <a href='./clearsessions.php'>clearing your session</a>.</p>

      <p>
        Links:
        <a href='http://github.com/abraham/twitteroauth'>Source Code</a> &amp;
        <a href='http://wiki.github.com/abraham/twitteroauth/documentation'>Documentation</a> |
        Contact @<a href='http://twitter.com/abraham'>abraham</a>
      </p>
      <hr />
      <?php if (isset($menu)) { ?>
        <?php echo $menu; ?>
      <?php } ?>
    </div>
    <?php if (isset($status_text)) { ?>
      <?php echo '<h3>'.$status_text.'</h3>'; ?>
    <?php } ?>
    <p>
            <pre>
       <!-- <?php print_r($content); ?>  -->

        <?php 
// if (isset($status_text)) {
        $count = 0;
        $max_id = 0;
        $i = 0;
        while($count < 5)
        {
          if ($count == 0) {
            $content = $connection->get('statuses/home_timeline', array('count' => '100'));
          }
          else{
            $content = $connection->get('statuses/home_timeline', array('max_id' => $max_id ,'count' => '100'));
          }

          foreach($content as $tweets) {
            echo $i++ . " : ";
            echo $tweets->text . "<br>";
            $max_id = $tweets->id;
          }
          $max_id = $max_id - 1;

          $count++;
        }
        // print_r($content); 
// }
        ?> 
        <!--
        <?php 

        $i = 0;
        foreach($content as $tweets) {
          echo $i++ . " : ";
          echo $tweets->text . "<br>";
        }

        ?>
        -->
      </pre>
    </p>

  </body>
</html>
