<?php get_header(); ?>

<div id="content">

	<?php if (have_posts()) : ?>
	
		<div>
			<h2 class="pagetitle">Search Results for &ldquo;<?php the_search_query(); ?>&rdquo;</h2>
			<div class="entry">&nbsp;</div>
		</div>

		<?php while (have_posts()) : the_post(); ?>
			<div id="post-<?php the_ID(); ?>" class="post">
				<p class="meta"><span class="posted">Posted by&nbsp;<?php the_author() ?></span><span class="date"><?php the_time('F jS, Y') ?></span></p>
				<h2 class="title"><a href="<?php the_permalink() ?>" rel="bookmark" title="Permanent Link to <?php the_title_attribute(); ?>"><?php the_title(); ?></a></h2>
				<div class="entry">
				<?php the_excerpt(); ?>
				</div>
			</div>
		<?php endwhile; ?>

		<div class="navigation">
			<div class="alignleft"><?php previous_posts_link('&laquo; Previous Entries') ?></div>
			<div class="alignright"><?php next_posts_link('Next Entries &raquo;') ?></div>
		</div>

	<?php else : ?>

		<div class="post">
			<h2 class="title">Search Results for &ldquo;<?php the_search_query(); ?>&rdquo;</h2>
			<div class="entry">
				<p>No posts found. Try a different search?</p>
			</div>
		</div>

	<?php endif; ?>

</div>
<!-- end content -->

<?php get_sidebar(); ?>

<?php get_footer(); ?>