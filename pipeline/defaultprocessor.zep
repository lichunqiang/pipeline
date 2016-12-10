namespace Pipeline;

class DefaultProcessor implements ProcessorInterface
{
	public function process(array! stages, var playload)
	{
		var stage;
		for stage in stages {
			let playload = {stage}(playload);
		}

		return playload;
	}
}